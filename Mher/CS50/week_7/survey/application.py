
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True

students = []


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
    name = request.form.get("name")
    city = request.form.get("city")
    gender = request.form.get("gender")
    if not name or not city or not gender:
        return "failure"
    File = open("survey.csv", "a")
    File.write(name + "," + city + "," + gender + '\n')
    File.close()
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as File:
        reader = csv.reader(File)
        students = list(reader)
    return render_template("success.html", students=students)


if __name__ == "__main__":
    app.run(debug=True)
