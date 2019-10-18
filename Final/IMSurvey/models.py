from datetime import datetime
from . import db


class User(db.Model):
    """Data model for user accounts."""

    __tablename__ = 'users'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    fullname = db.Column(db.String(64), nullable=False)
    email = db.Column(db.String(80), index=True, unique=True, nullable=False)
    password = db.Column(db.Text, index=False, unique=False, nullable=True)
    created = db.Column(db.DateTime, index=False, unique=False, default=datetime.utcnow)
    

    def __repr__(self):
        return f'<User id:{self.id}, email:{self.email}>'