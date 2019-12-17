#import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request, url_for

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
    if request.method == 'POST':
        name = request.form['name']
        age = request.form['age']
        house = request.form.get("house")
        position = request.form.get("position")
        print(position)
        if not name or not age or not house or not position:
            return render_template("error.html", message="TODO")
        with open ('survey.csv', 'a', newline='') as csvfile:
            filewriter = csv.writer(csvfile, delimiter=",",quotechar="|", quoting=csv.QUOTE_MINIMAL)
            filewriter.writerow([name,age,house,position])
        return redirect('sheet')
    else:    
        return render_template("error.html", message="TODO")
  


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open('survey.csv', 'r', newline='') as csvfile:
        filereader = csv.reader(csvfile)
        mylist = list(filereader) 
    return render_template('/sheet.html',mylist = mylist)


if __name__ == "__main__":
    app.run(debug=True)