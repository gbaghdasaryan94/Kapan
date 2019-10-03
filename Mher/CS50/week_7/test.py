from flask import Flask, render_template, request, redirect

app = Flask(__name__)

students = []

@app.route('/')
def index():
    return render_template("index.html")

@app.route('/registrants')
def registrants():
    return render_template("success.html", students = students)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    city = request.form.get("city")
    gender = request.form.get("gender")
    if not name or not city or not gender:
        return "failure"
    File = open("test.csv","a")
    File.write(name + "," + city + "," + gender + '\n')
    File.close()
    students.append(name)
    students.append(city)
    students.append(gender)
    return redirect("/registrants")

if __name__ == "__main__":
    app.run(debug = True)