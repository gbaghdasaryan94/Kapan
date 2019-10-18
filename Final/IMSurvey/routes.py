from flask import flash, jsonify, redirect, render_template, request, session, make_response

from datetime import datetime as dt
from flask import current_app as app

from .models import db, User
from .helpers import login_required


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
    # session["user_id"] = 15

    if request.method == "POST":

        email = request.form.get('email')
        password = request.form.get('password')
        print(email, password)
        
        if email and password:
            existing_user = User.query.filter(User.email == email).first()
            print(existing_user.id)
            if not existing_user:
                return make_response(f'{email} user not found!')
            session["user_id"] = existing_user.id

        return redirect("/")
    
    return render_template("login.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        fullname = request.form.get('fullname')
        email = request.form.get('email')
        password = request.form.get('password')
        confirm = request.form.get('confirm')
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