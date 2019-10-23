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

os.environ.setdefault("API_KEY", "pk_3cf9dc3be6c94508950443e1f7e59024")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    cash = db.execute("SELECT cash FROM users WHERE id =:id",
                      id=session["user_id"])
    rows = db.execute(
        "SELECT symbol, company, sum(count) AS count, price FROM history WHERE uid=:uid GROUP BY symbol HAVING sum(count) >= 1", uid=session["user_id"])
    prices = 0
    for i in range(len(rows)):
        prices += float(rows[i]['price']) * int(rows[i]['count'])

    db.execute("UPDATE users SET cash=10000 - :prices WHERE id=:id",
               prices=prices, id=session["user_id"])

    return render_template("index.html", rows=rows, cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        if not symbol:
            return apology("Not symbol")
        if not request.form.get("shares").isdigit():
            return apology("ESRgersg")
        shares = int(request.form.get("shares"))
        if shares < 1:
            return apology("EJRVWRVWRVJW")
        data = lookup(symbol)
        if not data:
            return apology("INVALID SYMBOL")
        price = float(data['price'])
        count = db.execute(
            "SELECT cash FROM users WHERE id=:id", id=session["user_id"])

        if shares * price > float(count[0]['cash']):
            return apology("YOU HAV'T STOLKO MONEY BRO")
        db.execute("INSERT INTO history(uid, symbol, company, count, price) VALUES(%s, %s, %s, %s, %s)",
                   (session["user_id"], symbol, data['name'], shares, data['price']))
        rows = db.execute(
            "SELECT symbol, company, sum(count) as count, price FROM history WHERE uid=:uid GROUP BY symbol HAVING sum(count) >= 1", uid=session["user_id"])
        prices = 0
        for i in range(len(rows)):
            prices += float(rows[i]['price']) * int(rows[i]['count'])
        db.execute("UPDATE users SET cash = 10000 - :prices WHERE id=:id",
                   prices=prices, id=session["user_id"])
        cash = db.execute(
            "SELECT cash FROM users WHERE id=:id", id=session["user_id"])

        return render_template("index.html", rows=rows, cash=cash)
    return render_template("buy.html")


@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    username = request.args.get("username") 
    rows = db.execute("SELECT username FROM users WHERE username = :username", username=username)
    if len(rows) < 1:
        return jsonify(True), 200
    else:
        return jsonify(False), 200

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT symbol, count, price, date FROM history WHERE uid = :uid", uid = session["user_id"])
    return render_template("history.html", history=history)


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
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("MISSING SYMBOL")
        data = lookup(symbol)
        if not data:
            return apology("SYMBOL DON'T MATCH")
        return render_template("quote.html", data=data)
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username").lower()
        password = request.form.get("password")
        agin = request.form.get("confirmation")
        if not username:
            return apology("MISSING USERNAME")
        if not password or not agin:
            return apology("MISSING PASSWORD")
        if password != agin:
            return apology("PASSWORD DON'T MATCH")
        password = generate_password_hash(password)
        rows = db.execute(
            "SELECT * FROM users WHERE username = :username", username=username)
        if len(rows):
            return apology("THIS NAME IS ZANYAT BRAT")
        session["user_id"] = db.execute(
            "INSERT INTO users(username,hash) VALUES(%s,%s)", (username, password))

        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("MISSING SYMBOL")
        shares = request.form.get("shares")
        if not shares:
            return apology("MISSING SHARES")
        shares = int(shares) * -1
        data = lookup(symbol)
        count = db.execute("SELECT symbol, sum(count) AS count FROM history WHERE uid=:uid  AND symbol=:symb",
                           uid=session["user_id"], symb=symbol)

        if abs(shares) > count[0]['count']:
            return apology("YOU HAVE NOT STOLKO ABRANQ")

        db.execute("INSERT INTO history(uid, symbol, company, count, price) VALUES(%s, %s, %s, %s, %s)",
                   (session["user_id"], symbol, data["name"], shares, data["price"]))

        rows = db.execute(
            "SELECT symbol, company, sum(count) AS count, price FROM history WHERE uid=:uid GROUP BY symbol", uid=session["user_id"])
        cash = db.execute(
            "SELECT cash FROM users WHERE id =:id", id=session["user_id"])
        prices = 0
        for i in range(len(rows)):
            prices += float(rows[i]['price']) * int(rows[i]['count'])
        db.execute("UPDATE users SET cash=10000 - :prices WHERE id=:id",
                   prices=prices, id=session["user_id"])
        return redirect("/")
    cash = db.execute("SELECT cash FROM users WHERE id =:id",
                      id=session["user_id"])
    rows = db.execute(
        "SELECT symbol, price, sum(count) AS count FROM history WHERE uid = :uid GROUP BY symbol HAVING sum(count) >= 1", uid=session["user_id"])
    print(rows)
    return render_template("sell.html", rows=rows, cash=cash)


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
