import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

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
    if not request.form.get("name"):
        return render_template("error.html", message="Missing Name")
    if not request.form.get("house"):
        return render_template("error.html", message="Missing House")
    if not request.form.get("position"):
        return render_template("error.html", message="Missing Position")
    name = request.form.get("name")
    position = request.form.get("position")
    house = request.form.get("house")
    with open('survey.csv', mode='a') as file:
        employee_writer = csv.writer(
            file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        employee_writer.writerow([name, house, position])
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    rows = []
    with open('survey.csv', mode='r') as file:
        rows = list(csv.reader(file))
    return render_template("sheet.html", rows=rows, n=len(rows))
