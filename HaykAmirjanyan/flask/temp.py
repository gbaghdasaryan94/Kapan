from flask import Flask, render_template

temp = Flask(__name__)
@temp.route('/')
def main_page():
    return render_template("index.html")

if __name__ == "__main__":
    temp.run(debug=True)