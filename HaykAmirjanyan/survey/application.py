import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True

lists = []


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
    if not request.form.get("inputname") or not request.form.get("house") or not request.form.get("position"):
        return render_template("error.html")
    name = request.form.get("inputname")
    home = request.form.get("house")
    radio = request.form.get("position")
    f = open("survey.csv", 'a')
    f.write(name + "," + home + "," + radio + "\n")
    f.close()
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as f:
        fb = csv.reader(f)
        lists = list(fb)
    return render_template("success.html", lists=lists)

if __name__ == "__main__":
    app.run(debug=True)