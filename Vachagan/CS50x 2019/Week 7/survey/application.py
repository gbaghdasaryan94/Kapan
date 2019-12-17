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


@app.route("/form", methods=["GET", "POST"])
def get_and_set_form():
    if request.method == "POST":
        name = request.form['name']
        lastname = request.form['lastname']
        city = request.form.get("city")
        color = request.form.get("color")
        if not name and not city and not color:
            return render_template("error.html", message="Please enter all fields!")
        with open("survey.csv", "a") as file:
            writer = csv.DictWriter(
                file, fieldnames=["name", "lastname", "city", "color"])
            if file.tell() == 0:
                writer.writeheader()
            writer.writerow({"name": name, "lastname": lastname,
                             "city": city, "color": color})
        return redirect("/sheet")
    return render_template("form.html")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as file:
        reader = csv.DictReader(file)
        sheets = list(reader)
    return render_template("sheet.html", sheets=sheets)


if __name__ == "__main__":
    app.run(debug=True)
