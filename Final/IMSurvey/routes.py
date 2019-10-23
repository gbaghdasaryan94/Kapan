from flask import flash, jsonify, redirect, render_template, request, session, make_response

from datetime import datetime as dt
from flask import current_app as app
from cs50 import SQL
from .models import db, User
from werkzeug.security import check_password_hash, generate_password_hash
from .helpers import login_required, apology
import re


# # Ensure responses aren't cached
# @app.after_request
# def after_request(response):
#     response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
#     response.headers["Expires"] = 0
#     response.headers["Pragma"] = "no-cache"
#     return response

db = SQL("sqlite:///IMSurvey/survey.db")

@app.route('/', methods=['GET'])
@login_required
def home():
    user = User.query.get_or_404(session["user_id"])
    return render_template('onboarding.html', user=user, title="Show Users")

@app.route('/login', methods=['GET', 'POST'])
def login():

    session.clear()

    if request.method == "POST":
        email = request.form.get('email')
        password = request.form.get('password')

        if not email:
            return apology("Please enter email")
        if not password:
            return apology("Please enter password")
        
        em = db.execute("SELECT * FROM users WHERE email = :email", email = email)
        if not em or check_password_hash(em[0]["password"], request.form.get("password")):
            return apology("Email or password is invalid")
        session["user_id"] = em[0]['id']
        return redirect("/")
    return render_template("login.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        fullname = request.form.get('fullname')
        email = request.form.get('email')
        password = request.form.get('password')
        if (len(password)<6) or not re.search(r"([a-z]|[A-Z]+[0-9]+[/S])", password):
            return apology("Wrong Password", 400)
        if not re.search(r"([a-z]|[A-Z]+[/s])",fullname):
            return apology("Wrong Fullname", 400)


        confirm = request.form.get('confirm')
        if fullname and email and password and password == confirm:
            existing_user = User.query.filter(User.email == email).first()
            if existing_user:
                return make_response(f'{email} already created!')
            
            new_user = User(fullname=fullname, email=email, password=generate_password_hash(request.form.get("password")))
            
            db.session.add(new_user)
            db.session.commit()

            session["user_id"] = new_user.id
        return redirect("/")
    
    return render_template("register.html")

@app.route('/logout')
def logout(): 
    session.clear()
    return redirect("/")

@app.route('/account')
def my_account(): 
    return render_template("account.html")