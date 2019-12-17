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

# Make sure API key is set
os.environ.setdefault("API_KEY", "pk_fb4ada2ef3864efcb20aa455efac6d5b")
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    tab = db.execute(
        "SELECT symbol, name, sum(shares) as shares, price FROM transactions WHERE uid = :uid GROUP BY symbol HAVING sum(shares)>=1", uid=session["user_id"])
    money = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])[0]["cash"]
    total = money
    for item in tab:
        item["price"] = lookup(item["symbol"])["price"]
        total += item["shares"]*item["price"]
    return render_template("index.html", tab=tab, money=money, total=total)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    symbol = request.form.get("symbol")
    share = request.form.get("shares")
    summary = 0
    # Get the current users's cash
    remaining = db.execute(
        "SELECT cash FROM users WHERE id = :id", id=session["user_id"])
    cash = int(remaining[0]["cash"])
    if request.method == "POST":
        symbol = symbol.upper()
        if not symbol:
            return apology("Missing Symbol")
        elif not symbol.isalpha():
            return ("Invalid Symbol")
        elif not share:
            return apology("Missing Shares")
        elif not share.isdigit():
            return apology("Not a digit")
        elif int(share) <= 0:
            return apology("Cannot accept negative numbers")
        else:
            table = lookup(symbol)
            if table:
                if (int(share) * table["price"]) < cash:
                    db.execute("INSERT INTO transactions (symbol, shares, name, price, uid) VALUES (:symbol, :shares, :name, :price, :uid)",
                               symbol=symbol, shares=int(share), name=table["name"], price=table["price"], uid=session["user_id"])
                    tab = db.execute(
                        "SELECT symbol, name, shares, price FROM transactions WHERE uid = :uid", uid=session["user_id"])
                    for j in range(len(tab)):
                        summary += tab[j]["shares"] * tab[j]["price"]
                    db.execute("UPDATE users SET cash = 10000 -:summ WHERE id =:id",
                               id=session["user_id"], summ=summary)
                else:
                    return apology("You cannot afford it")
            else:
                return apology("Invalid table")
        return redirect("/")

    return render_template("buy.html")


@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    return jsonify(not bool(len(db.execute("SELECT username FROM users WHERE username = :username", username=request.args.get("username"))))), 200


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    transaction = db.execute(
        "SELECT symbol, shares, price, transacted FROM transactions where uid=:uid", uid=session["user_id"])
    return render_template("history.html", transaction=transaction)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["password"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

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
    """Check the price of the stock"""
    if request.method == "POST":

        symbol = request.form.get("symbol")
        table = lookup(symbol)
        if table:
            return render_template("quoted.html", Name=table["name"], Price=table["price"], Symbol=table["symbol"])
        return apology("Could not find the Symbol")

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        un = request.form.get("username").lower()
        pw = request.form.get("password")
        cpw = request.form.get("confirmation")
        hashpw = generate_password_hash(pw)
        rows = db.execute(
            "SELECT * FROM users WHERE username = :username", username=un)
        if not un or not pw or not cpw:
            return apology("Please fill the form before registering")
        elif pw != cpw:
            return apology("Passwords do not match!!!")
        elif len(rows) == 1:
            return apology("The given username is taken!!!")
        else:
            # add the user to DB
            user_id = db.execute(
                "INSERT INTO users (username,password) VALUES (:username, :password)", username=un, password=hashpw)
        if not user_id:
            return apology("Something went wrong")
        session["user_id"] = user_id
        return redirect("/")
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        smb = db.execute(
            "SELECT symbol FROM transactions WHERE uid = :uid GROUP BY symbol HAVING sum(shares)>=1", uid=session["user_id"])
        return render_template("sell.html", smb=smb)
    # request.method == "POST":
    sm = request.form.get("symbol")
    share = request.form.get("shares")
    if not sm:
        return apology("Missing Symbol")
    elif not share:
        return apology("Missing Share")

    table = lookup(sm)
    qty = db.execute(
        "SELECT SUM(shares) AS shares FROM transactions WHERE uid = :uid GROUP BY symbol HAVING sum(shares)>0", uid=session["user_id"])
    print(qty)
    if int(share) > int(qty[0]["shares"]):
        return apology("You exceeded maximum number of shares")

    db.execute("INSERT INTO transactions (symbol, shares, name, price, uid) VALUES (:symbol, 0 - :shares, :name, :price, :uid)",
               symbol=sm, shares=int(share), name=table["name"], price=table["price"], uid=session["user_id"])
    summary = int(share) * table["price"]
    db.execute("UPDATE users SET cash = cash+:summ WHERE id =:id",
               id=session["user_id"], summ=summary)
    return redirect("/")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
