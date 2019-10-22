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

os.environ.setdefault("API_KEY", "pk_5002261727a549b0a396b564ed99e90d")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    rows = db.execute("SELECT * FROM purchase WHERE uid = :uid",
                      uid=session["user_id"])
    remain = db.execute(
        "SELECT cash FROM users WHERE id = :uid", uid=session["user_id"])
    return render_template("index.html", rrows=rows, cash=remain[0]["cash"])


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":

        if not request.form.get("symbol") or not request.form.get("shares"):
            return apology("Please fill in all the fields")

        info = lookup(request.form.get("symbol"))
        if not info:
            return apology("stock is not valid", 400)

        if not request.form.get("shares").isdigit():
            return apology("please enter number", 400)

        shares = int(request.form.get("shares"))

        if shares < 1:
            return apology("enter poitive integer", 400)

        total = float(info['price']) * shares

        if not request.form.get("shares").isdigit() or shares < 1:
            return apology("please enter poitive integer", 400)

        # check if total<cash
        c = db.execute("SELECT cash FROM users WHERE id = :uid",
                       uid=session["user_id"])

        if c[0]["cash"] < total:
            return apology("pox chka")

        # if symbol already exists, UPDATE the shares and total, else INSERT INTO
        p = db.execute("SELECT * FROM purchase WHERE uid = :uid",
                       uid=session["user_id"])
        # list of symbols in base
        symbase = []
        for i in range(len(p)):
            symbase.append(p[i]['symbol'])

        for i in range(len(p)):
            if info['symbol'] == p[i]['symbol']:
                db.execute("UPDATE purchase SET shares = shares + :sh, total = price * (shares + :sh) WHERE uid = :uid AND symbol = :sym",
                           sh=shares, uid=session["user_id"], sym=info['symbol'])

        if info['symbol'] not in symbase:
            # insert into purchase table
            db.execute("INSERT INTO purchase (symbol, name, shares, price, total, uid) VALUES (:symbol, :name, :shares, :price, :total, :uid)",
                       symbol=info['symbol'], name=info['name'], price=info['price'], shares=shares, total=total, uid=session["user_id"])

        db.execute("UPDATE users SET cash = cash - :tt WHERE id = :uid",
                   uid=session["user_id"], tt=total)

        db.execute("INSERT INTO history (symbol, price, shares, uid) VALUES (:symbol, :price, :shares, :uid)",
                   symbol=info['symbol'], price=info['price'], shares=shares, uid=session['user_id'])

        rows = db.execute(
            "SELECT * FROM purchase WHERE uid = :uid", uid=session["user_id"])
        remain = db.execute(
            "SELECT cash FROM users WHERE id = :uid", uid=session["user_id"])
        return render_template("index.html", rrows=rows, cash=remain[0]["cash"])

    return render_template("buy.html")


@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    username = request.args.get("username")
    un = db.execute(
        "SELECT * FROM users WHERE username = :username", username=username)
    if un:
        return jsonify(False), 200
    else:
        return jsonify(True), 200


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    rows = db.execute("SELECT * FROM history WHERE uid = :uid",
                      uid=session["user_id"])
    return render_template("history.html", rr=rows)


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
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
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
    if request.method == "POST":
        info = lookup(request.form.get("symbol"))
        if not info:
            return apology("stock is not valid")
        return render_template("quoted.html", name=info['name'], price=info['price'], symbol=info['symbol'])

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":

        if not request.form.get("username"):
            return apology("must provide username", 400)

        elif not request.form.get("password"):
            return apology("must provide password", 400)

        elif request.form.get("confirmation") != request.form.get("password"):
            return apology("passwords do not match", 400)

        # TODO check the username is available or not
        un = db.execute("SELECT username FROM users")

        for i in range(len(un)):
            if request.form.get("username") == un[i]['username']:
                return apology("username is not available")

        # NSERT INTO db
        session["user_id"] = db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                                        username=request.form.get("username"), hash=generate_password_hash(request.form.get("password")))

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "POST":

        if not request.form.get("shares"):
            return apology("Please fill in all the fields")

        info = lookup(request.form.get("symbol"))
        shares = int(request.form.get("shares"))
        total = float(info['price']) * shares

        # check if there are enough shares in purchase base
        shb = db.execute("SELECT shares FROM purchase WHERE uid = :uid AND symbol = :sym",
                         uid=session["user_id"], sym=info['symbol'])

        if shares > shb[0]['shares']:
            return apology("There are no enough shares")

        else:
            db.execute("UPDATE purchase SET shares = shares - :sh, total = price * (shares - :sh) WHERE uid = :uid AND symbol = :sym",
                       sh=shares, uid=session["user_id"], sym=info['symbol'])

        db.execute("DELETE FROM purchase WHERE shares = 0")

        db.execute("UPDATE users SET cash = cash + :tt WHERE id = :uid",
                   uid=session["user_id"], tt=total)

        db.execute("INSERT INTO history (symbol, price, shares, uid) VALUES (:symbol, :price, :shares, :uid)",
                   symbol=info['symbol'], price=info['price'], shares=-1 * shares, uid=session['user_id'])

        rows = db.execute(
            "SELECT * FROM purchase WHERE uid = :uid", uid=session["user_id"])
        remain = db.execute(
            "SELECT cash FROM users WHERE id = :uid", uid=session["user_id"])
        return render_template("index.html", rrows=rows, cash=remain[0]["cash"])

    else:
        s = db.execute(
            "SELECT symbol FROM purchase WHERE uid = :uid", uid=session["user_id"])
        return render_template("sell.html", s=s)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
