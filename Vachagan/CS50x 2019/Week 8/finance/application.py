import os

import requests
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

os.environ.setdefault("API_KEY", "pk_9f2f9e37df674e3e95dfe26704be7ebe")
# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if not session["user_id"]:
        return redirect("/login")

    user = db.execute("SELECT cash FROM users WHERE id = %s",
                      (session["user_id"]))[0]

    data = db.execute(
        "SELECT SUM(shares) as shares, price, name, symbol FROM history WHERE uid = %s GROUP BY name HAVING SUM(shares) > 0", (session["user_id"]))
    total = user["cash"]
    if data:
        for i in range(len(data)):
            data[i]["price"] = lookup(data[i]["symbol"])["price"]
            total += data[i]["shares"] * data[i]["price"]
    return render_template("home.html", user=user, data=data, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        symbol = request.form["symbol"]

        if request.form["shares"].isdigit():
            shares = int(request.form["shares"])
            if shares <= 0:
                return apology("shares can't be negative or zero")
            data = lookup(symbol)
            if not data:
                return apology("invalid symbol", 400)

            cash = db.execute("SELECT cash FROM users WHERE id = %s", (session["user_id"]))[
                0]["cash"]

            card = shares * data["price"]
            if card > cash:
               return apology("invalid cash", 400)

            if db.execute("INSERT INTO history (symbol, name, uid, shares, price) VALUES (%s, %s, %s, %s, %s)", (data["symbol"], data["name"], session["user_id"], shares, data["price"])) and db.execute("UPDATE users SET cash = %s WHERE id = %s", (cash - card, session["user_id"])):
                flash("Bought!")

            return redirect("/")
        return apology("invalid shares", 400)
    return render_template("buy.html")


@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    return jsonify(not bool(len(db.execute("SELECT * FROM users WHERE username = %s", request.args.get('username'))))), 200


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    data = db.execute(
        "SELECT shares, price, name, symbol, date FROM history WHERE uid = %s", (session["user_id"]))
    print(data)
    return render_template("history.html", data=data)


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
    """Get stock quote."""

    if request.method == "POST":
        symbol = request.form["symbol"]
        data = lookup(symbol)
        if not data:
            return apology("invalid symbol", 400)

        return render_template("quote.html", data=data)

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        username = request.form.get("username").lower()
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif db.execute('SELECT * FROM users WHERE username = :username', username=username):
            return apology('username already exists!', 400)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 400)

        # Ensure password was submitted
        elif not confirmation:
            return apology("must provide confirmation", 400)

        # Ensure password was submitted
        elif password != confirmation:
            return apology("password not equal", 400)

        # Query database for username
        res = db.execute("INSERT INTO users (username, hash) VALUES (%s, %s)",
                         (username, generate_password_hash(password)))

        # Ensure username exists and password is correct
        if not res:
            return apology("Somting wrong", 404)

        session["user_id"] = res
        session["username"] = username
        flash("Registered!")
        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        symbol = request.form["symbol"]

        if request.form["shares"].isdigit():
            shares = int(request.form["shares"])

            if shares <= 0:
                return apology("shares can't be negative or zero")

            dshares = db.execute("SELECT SUM(shares) as shares FROM history WHERE symbol = %s and uid = %s GROUP BY name", (
                symbol, session["user_id"]))[0]["shares"]

            if dshares < shares:
                return apology("shares is not avaible", 400)

            ldata = lookup(symbol)

            if not ldata:
                return apology("something wrong", 400)

            cash = db.execute("SELECT cash FROM users WHERE id = %s", (session["user_id"]))[
                0]["cash"]

            cash += shares * ldata["price"]

            if db.execute("INSERT INTO history (symbol, name, uid, shares, price) VALUES (%s, %s, %s, %s, %s)", (symbol, ldata["name"], session["user_id"], 0-shares, ldata["price"])) and db.execute("UPDATE users SET cash = %s WHERE id = %s", (cash, session["user_id"])):
                flash("Sold!")

            return redirect("/")
        return apology("invalid shares", 400)
    data = db.execute(
        "SELECT symbol, name FROM history WHERE uid = %s GROUP BY name  HAVING SUM(shares) > 0", session["user_id"])
    return render_template("sell.html", data=data)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)

if __name__ == "__main__":
    app.run(debug=True)
