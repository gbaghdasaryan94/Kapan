from flask import flash, jsonify, redirect, render_template, request, session, make_response

from datetime import datetime
from flask import current_app as app
from .models import db, User, EWIinfo
from werkzeug.security import check_password_hash, generate_password_hash
from .helpers import login_required, apology, allowed_image
import re
import os

from flask_mail import Mail, Message
mail = Mail(app)

# flash -->  flash("message", "status")  stasus -> primary, secondary, success, danger, warning, info, light, dark

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route('/', methods=['GET', 'POST'])
# @login_required
def home():
    
    if session.get("user_id"):
        user = User.query.filter_by(id=session["user_id"]).first()
        if not user.isComplete:
            return redirect("/onboarding")
        return render_template('home.html')
        
    return render_template('index.html')

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
        
        user = User.query.filter_by(email=email).first()
        if not user or not check_password_hash(user.password, password):
            flash("Email or password is invalid", "warning")
            return redirect("/")
        session["user_id"] = user.id

    return redirect("/")

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        fullname = request.form.get('fullname')
        email = request.form.get('email')
        password = request.form.get('password')
        confirm = request.form.get('confirm')
        if not (fullname and email and password and password == confirm):
            flash("Error any fields is empty", "danger")
            return redirect("/")
        if not re.search(r"^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{6,}$", password):
            flash("Password is incorrect", "danger")
            return redirect("/")
        if not re.search(r"([a-z]|[A-Z]+[/s])",fullname):
            flash("Fullname is incorrect", "danger")
            return redirect("/")
            
        existing_user = User.query.filter(User.email == email).first()
        if existing_user:
            return make_response(f'{email} already created!')
        
        new_user = User(fullname=fullname, email=email, password=generate_password_hash(request.form.get("password")))
        
        db.session.add(new_user)
        db.session.commit()

        session["user_id"] = new_user.id

        return redirect("/onboarding")
    
    return render_template("register.html")


@app.route("/onboarding", methods = ["GET", "POST"])
@login_required
def onboarding():
    user = User.query.filter_by(id = session.get("user_id"))
    if user[0].isComplete:
        return redirect("/")
    if request.method == "POST":
        data = request.form.to_dict(flat=True)
        if request.files:
            image = request.files["avatar"]
            if not image.filename:
                flash("No filename", "danger")
                return

            if allowed_image(image.filename):
                filename = os.path.join(app.config['IMAGE_UPLOADS'], f"{datetime.now().strftime('%m%s')}.jpg")
                
                image.save(''.join([app.config['APP_ROOT'],filename]))
                data["avatar"] = filename
                data["birth"] = datetime.strptime(data["birth"], "%m/%d/%Y").date()
                data["isComplete"] = True
                print(data)
                user.update(data)
                # db.session.query(User).filter_by(id = 2).update(data)
                db.session.commit()
                return redirect("/")
            else:
                return "That file extension is not allowed"   

    return render_template("onboarding.html", fullname=user[0].fullname)



@app.route("/fill-cv", methods = ["GET", "POST"])
@login_required
def fill_cv():

    if request.method == "POST":
        data = request.form.to_dict(flat=True)
        data["uid"] = session["user_id"]
        data["start"] = datetime.strptime(data["start"], "%Y-%m-%d").date()
        data["finish"] = datetime.strptime(data["finish"], "%Y-%m-%d").date()
        new_info = EWIinfo(**data)

        db.session.add(new_info)
        db.session.commit()

    return redirect("/")


@app.route('/logout')
def logout(): 
    session.clear()
    return redirect("/")

@app.route('/account')
def my_account(): 
    return render_template("account.html")


@app.route('/contact',methods=["GET","POST"])
def contact():
    if request.method =="POST":
        name = request.form.get("name")
        lastName = request.form.get("lastName")
        email = request.form.get("email")
        phone = request.form.get("phone")
        text = request.form.get("text")
        if not name:
           pass
        if not lastName:
            pass
        if not email:
            pass
        if not phone:
            pass
        if not text:
            pass

        msg = Message("Message from IMsurvey",recipients=['hamona777@mail.ru', 'imsurvey@kit.am'])
        # msg.body = 'This is a test mail body'
        msg.html = f"From: {name} {lastName} <br>Email: {email}<br>Phone: {phone}<br><br>Message:<br>{text}"
        mail.send(msg)

        flash('Your email was sent successfully', "success")
    
    return redirect("/") 
