from flask import Flask, render_template, request
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

app = Flask(__name__)
app.config['SQLAlCHEMY_DATABASE_URI'] = 'sqlite:///todo.db'
db = SQLAlchemy(app)

class toDo(db_Models):
    id = db.Column(db,Integer, primary_key=True)
    content = db.Column(db.String(200), nullable=False)
    data_creat = db.Column(db.DateTime, default=datetime.utcnow)
    def __repr__(self):
        return self.id

@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        pass
    else:
        return "Hello"    

if __name__ == "__main__":
    Flask.run(debug=True)