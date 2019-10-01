from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    dorm = request.form.get("dorm")
    if not name or not dorm:
        return "failure"
    File = open("test.txt","a")
    File.write(name + " from " + dorm +'\n')
    File.close()
    return render_template("success.html")

if __name__ == "__main__":
    app.run(debug = True)