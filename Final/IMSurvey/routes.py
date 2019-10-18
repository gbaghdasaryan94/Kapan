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
    """Create a user."""
    username = request.args.get('user')
    email = request.args.get('email')
    if username and email:
        existing_user = User.query.filter(User.username == username or User.email == email).first()
        if existing_user:
            return make_response(f'{username} ({email}) already created!')
        new_user = User(username=username,
                        email=email,
                        created=dt.now(),
                        bio="In West Philadelphia born and raised, on the playground is where I spent most of my days",
                        admin=False)  # Create an instance of the User class
        db.session.add(new_user)  # Adds new User record to database
        db.session.commit()  # Commits all changes

    return render_template('users.html',
                           users=User.query.all(),
                           title="Show Users")



@app.route('/login', methods=['GET', 'POST'])
def login():
    session["user_id"] = 15
    return redirect("/")


@app.route('/logout')
def logout():
    
    session.clear()
    return redirect("/")