import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")
os.environ.setdefault("API_KEY", "pk_e9e7c25b0dff435c87402c4b245d904c")
# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    history = db.execute(
        "SELECT symbol, name, sum(share) AS share, price, date FROM history WHERE uid=:uid GROUP BY symbol", uid=session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id=:uid", uid=session["user_id"])[0]["cash"]
    total = 0
    for amy in history:
        amy['price'] = lookup(amy['symbol'])['price']
        total = amy['price'] * amy['share']
        print(total)
    return render_template("index.html", result=history, cash=cash, tatol=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)
        if not request.form.get("shares"):
            return apology("must provide shares", 400)
        result = lookup(request.form.get("symbol"))
        if not result:
            return apology("must provide existing symbol", 400)
        try: 
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("must provide existing symbol", 400)
        if shares < 0:
            return apology("must provide existing symbol", 400)
        cash = int(db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])[0]["cash"])
        if shares * result['price'] > cash:
            return apology("no enough cash", 400)
        else:
            db.execute("INSERT INTO history (uid, symbol, name, share, price) VALUES (:uname, :symb, :name, :share, :price )", uname=session["user_id"],
                       symb=result["symbol"], name=result["name"], share=shares, price=result["price"])
            db.execute("UPDATE users SET cash=:cash WHERE id=:uid", uid=session["user_id"], cash=(cash - shares * result['price']))
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    if len(db.execute("SELECT * FROM users WHERE username = :username", username=request.args.get("username"))):
        return jsonify(False), 200
    else:
        return jsonify(True), 200


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT symbol, share, price, date FROM history WHERE uid=:uid", uid=session["user_id"])
    return render_template("history.html", result=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)
        result = lookup(request.form.get("symbol"))
        if not result:
            return apology("must provide symbol", 400)
        # Redirect user to home page
        return render_template("quote.html", result=result)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")
    

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        
        # Forget any user_id
        session.clear()

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure password confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide password confirmation", 400)
            
        # Ensure passwords match 
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords doesn't match", 400)

        # Query database for username
        elif len(db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))):
            return apology("username is already in use", 400)

        # Add to db
        session["user_id"] = db.execute("INSERT INTO users (username, hash) VALUES (:uname, :pword)", uname=request.form.get("username"),
                                        pword=generate_password_hash(request.form.get("password")))

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)
        if not request.form.get("shares"):
            return apology("must provide shares", 400)
        result = lookup(request.form.get("symbol"))
        if not result:
            return apology("must provide existing symbol", 400)
        shares = int(request.form.get("shares"))
        poisk = db.execute("SELECT sum(share) AS share FROM history WHERE uid=:id AND symbol=:symb GROUP BY symbol",
                           symb=request.form.get("symbol").upper(), id=session["user_id"])
        if not poisk:
            return apology("must provide existing symbol", 400)
        count = int(poisk[0]["share"])
        if shares > count:
            return apology("no enough share", 400)
        else:
            db.execute("INSERT INTO history (uid, symbol, name, share, price) VALUES (:uname, :symb, :name, :share, :price )", uname=session["user_id"],
                       symb=result["symbol"], name=result["name"], share=(0 - shares), price=result["price"])
            db.execute("UPDATE users SET cash= cash + :cash WHERE id=:uid", uid=session["user_id"], cash=(shares * result['price']))
        return redirect("/")
    else:
        poisk = db.execute("SELECT symbol, sum(share) AS share FROM history WHERE uid=:id GROUP BY symbol", id=session["user_id"])
        return render_template("sell.html")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
