from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template("index.html")

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
    return render_template("success.html")

if __name__ == "__main__":
    app.run(debug = True)