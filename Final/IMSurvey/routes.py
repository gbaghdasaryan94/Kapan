from flask import flash, jsonify, redirect, render_template, request, session, make_response

from datetime import datetime as dt
from flask import current_app as app

from .models import db, User
from .helpers import login_required, apology
import re


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route('/', methods=['GET'])
@login_required
def home():
    users = User.query.all()
    print(users)
    return render_template('index.html', users=users, title="Show Users")

@app.route('/login', methods=['GET', 'POST'])
def login():
    session["user_id"] = 15
    return redirect("/")

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
        print(fullname, email, password, confirm)
        if fullname and email and password and password == confirm:
            existing_user = User.query.filter(User.email == email).first()
            if existing_user:
                return make_response(f'{email} already created!')
            
            new_user = User(fullname=fullname, email=email, password=password)

            db.session.add(new_user)
            db.session.commit()
        return redirect("/")
    
    return render_template("register.html")

@app.route('/logout')
def logout(): 
    session.clear()
    return redirect("/")