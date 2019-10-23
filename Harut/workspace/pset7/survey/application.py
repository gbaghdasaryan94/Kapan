import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

students = []

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    # TODO
    name = request.form.get("name")
    age = request.form.get("age")
    city = request.form.get("city")
    gender = request.form.get("gender")
    if not name or not age or not city or not gender:
        return render_template("error.html", message="Fill in all the fields!")
    f = open("survey.csv", "a")
    f.write(name + ',' + age + ',' + city + ',' + gender + '\n')
    f.close()
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    # TODO
    f = open("survey.csv", "r")
    reader = csv.reader(f)
    students = list(reader)
    f.close()
    return render_template("sheet.html", students=students)