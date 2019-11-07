from flask import flash, jsonify, redirect, render_template, request, session, make_response

from datetime import datetime
from flask import current_app as app
from .models import db, User, EWIinfo, Skillinfo
from werkzeug.security import check_password_hash, generate_password_hash
from .helpers import login_required, apology, allowed_image
import os
import re
import pdfkit
import time

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
        if not re.search(r"([a-z]|[A-Z]+[/s])", fullname):
            flash("Fullname is incorrect", "danger")
            return redirect("/")

        existing_user = User.query.filter(User.email == email).first()
        if existing_user:
            flash(f'{email} already created!', "warning")
            return redirect("/")
        new_user = User(fullname=fullname, email=email, password=generate_password_hash(
            request.form.get("password")))

        db.session.add(new_user)
        db.session.commit()

        session["user_id"] = new_user.id

        return redirect("/onboarding")

    return render_template("register.html")


@app.route("/onboarding", methods=["GET", "POST"])
@login_required
def onboarding():
    user = User.query.filter_by(id=session.get("user_id"))
    if user[0].isComplete:
        return redirect("/")
    if request.method == "POST":
        data = request.form.to_dict(flat=True)
        if request.files:
            image = request.files["avatar"]
            if image and allowed_image(image.filename):
                filename = os.path.join(
                    app.config['IMAGE_UPLOADS'], f"{datetime.now().strftime('%m%s')}.jpg")
                  
                if not os.path.exists('/IMSurvey/'.join([app.config['APP_ROOT'], app.config['IMAGE_UPLOADS']])):
                    os.makedirs('/IMSurvey/'.join([app.config['APP_ROOT'], app.config['IMAGE_UPLOADS']]))
                image.save('/IMSurvey/'.join([app.config['APP_ROOT'], filename]))
                data["avatar"] = filename
                data["birth"] = datetime.strptime(
                    data["birth"], "%Y-%m-%d").date()
                data["isComplete"] = True
                print(data)
                user.update(data)
                # db.session.query(User).filter_by(id = 2).update(data)
                db.session.commit()
                return redirect("/")
            else:
                return "That file extension is not allowed"

    return render_template("onboarding.html", fullname=user[0].fullname)


@app.route("/fill-info", methods=["GET", "POST"])
@login_required
def fill_EWIinfo():

    if request.method == "POST":
        data = request.form.to_dict(flat=True)
        data["uid"] = session["user_id"]
        try:
            data["start"] = datetime.strptime(data["start"], "%Y-%m-%d").date()
            data["finish"] = datetime.strptime(
                data["finish"], "%Y-%m-%d").date()
        except ValueError:
            flash("You need to spicify the dates", "danger")
            return redirect("/")
        new_info = EWIinfo(**data)

        db.session.add(new_info)
        db.session.commit()

    return redirect("/")


@app.route("/fill-skill", methods=["GET", "POST"])
@login_required
def fill_Skillinfo():

    if request.method == "POST":
        data = request.form.to_dict(flat=True)
        data["uid"] = session["user_id"]
        new_skill = Skillinfo(**data)

        db.session.add(new_skill)
        db.session.commit()

    return redirect("/")


@app.route('/logout')
def logout():
    session.clear()
    return redirect("/")


@app.route('/account', methods=["GET", "POST"])
@login_required
def my_account():
    user = User.query.filter_by(id=session.get("user_id"))
    if not user[0].isComplete:
        return redirect("/")
    
    if request.method == "POST":
        if request.form.get("type"):
            if request.form.get("type") == "remove":
                table = request.form.get("table")
                if table == "info":
                    EWIinfo.query.filter_by(id = request.form.get("data"), uid=session.get("user_id")).delete()
                elif table == "skill":
                    Skillinfo.query.filter_by(id = request.form.get("data"), uid=session.get("user_id")).delete()
                else:
                    User.query.filter_by(id = request.form.get("data"), uid=session.get("user_id")).delete()
                db.session.commit()
                return jsonify(True), 200
            elif request.form.get("type") == "change":
                
                table = request.form.get("table")
                data = request.form.to_dict(flat=True)

                try:
                    data["start"] = datetime.strptime(data["start"], "%Y-%m-%d").date()
                    data["finish"] = datetime.strptime(
                        data["finish"], "%Y-%m-%d").date()
                except ValueError:
                    return jsonify(False), 500
                    
                del data["type"]
                del data["table"]
                del data["id"]
                print(data)
                if table == "info":
                    db.session.query(EWIinfo).filter_by(id = request.form.get("id"), uid=session.get("user_id")).update(data)
                # elif table == "skill":
                #     Skillinfo.update(data)
                # else:
                #     User.update(data)
                db.session.commit()
                return jsonify(True), 200
                # for item in request.form:
                #     print(item)
            return jsonify(False), 500
        # data = request.form.to_dict(flat=True)

        # if not re.search(r"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)", data["email"]):
        #     flash("Email is incorrect", "warning")
        #     return redirect(request.url)
        # if not re.search(r"([a-z]|[A-Z]+[/s])", data["fullname"]):
        #     flash("Fullname is incorrect", "danger")
        #     return redirect("/")

        # data["birth"] = datetime.strptime(data["birth"], "%Y-%m-%d").date()
        # user.update(data)
        # db.session.commit()

    edu_info = EWIinfo.query.filter_by(uid=session.get("user_id"), info="education").all()
    intership_info = EWIinfo.query.filter_by(uid=session.get("user_id"), info="intership").all()
    work_info = EWIinfo.query.filter_by(uid=session.get("user_id"), info="work").all()

    prof_skill = Skillinfo.query.filter_by(uid=session.get("user_id"), info="prof").all()
    pers_skill = Skillinfo.query.filter_by(uid=session.get("user_id"), info="pers").all()
    hobby_skill = Skillinfo.query.filter_by(uid=session.get("user_id"), info="hobby").all()
    
    return render_template("account.html", user=user[0], edu=edu_info, inter=intership_info, work=work_info, prof=prof_skill, pers=pers_skill, hobby=hobby_skill)



@app.route('/contact', methods=["GET", "POST"])
def contact():
    if request.method == "POST":
        name = request.form.get("name")
        lastName = request.form.get("lastName")
        email = request.form.get("email")
        phone = request.form.get("phone")
        text = request.form.get("text")
        if not (name and lastName and email and phone and text):
            pass

        msg = Message("Message from IMsurvey", recipients=[
                      'hamona777@mail.ru', 'imsurvey@kit.am'])
        # msg.body = 'This is a test mail body'
        msg.html = f"From: {name} {lastName} <br>Email: {email}<br>Phone: {phone}<br><br>Message:<br>{text}"
        mail.send(msg)

        flash('Your email was sent successfully', "success")

    return redirect("/")


@app.route('/topdf/<int:version>', methods=["GET"])
@login_required
def pdf_converter(version):
    print(version)
    config = pdfkit.configuration(wkhtmltopdf="./wkhtmltopdf")

    options = {
        'page-size': 'A4',
        'margin-top': '0.5in',
        'margin-right': '0.5in',
        'margin-bottom': '0.5in',
        'margin-left': '0.5in',
        'encoding': "UTF-8",
        'dpi': 300
    }

    user = User.query.filter_by(id=session.get("user_id")).first()
    user.avatar = os.path.join(app.config['APP_STATIC_ROOT'], user.avatar)

    edu_info = EWIinfo.query.filter_by(uid=session.get("user_id"), info="education").all()
    intership_info = EWIinfo.query.filter_by(uid=session.get("user_id"), info="intership").all()
    work_info = EWIinfo.query.filter_by(uid=session.get("user_id"), info="work").all()

    prof_skill = Skillinfo.query.filter_by(uid=session.get("user_id"), info="prof").all()
    pers_skill = Skillinfo.query.filter_by(uid=session.get("user_id"), info="pers").all()
    hobby_skill = Skillinfo.query.filter_by(uid=session.get("user_id"), info="hobby").all()

    

    rendered = render_template(f"resume/{version}.html", user=user, edu=edu_info, inter=intership_info, work=work_info, prof=prof_skill, pers=pers_skill, hobby=hobby_skill)
    css = [os.path.join(app.config['APP_STATIC_ROOT'], 'static/resume/grid4.css'), os.path.join(app.config['APP_STATIC_ROOT'], f'static/resume/{version}.css')]

    pdf = pdfkit.from_string(rendered, False, css=css, configuration=config, options=options)

    response = make_response(pdf)
    response.headers['Content-Type'] = 'application/pdf'
    # response.headers['Content-Disposition'] = f'attachment; filename=CV({user.fullname}).pdf'
    response.headers['Content-Disposition'] = f'inline; filename=CV({user.fullname}).pdf'
    return response
