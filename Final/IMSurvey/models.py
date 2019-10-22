from datetime import datetime
from . import db


class User(db.Model):
    """Data model for user accounts."""

    __tablename__ = 'users'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    fullname = db.Column(db.String(64), nullable=False)
    email = db.Column(db.String(80), index=True, unique=True, nullable=False)
    password = db.Column(db.Text, index=False, unique=False, nullable=False)
    birth = db.Column(db.Date)
    phone = db.Column(db.Text)
    sex = db.Column(db.String(12))
    address = db.Column(db.Text)
    avatar = db.Column(db.Text)
    status = db.Column(db.Text)
    children = db.Column(db.Integer)
    about = db.Column(db.Text)
    notes = db.Column(db.Text)
    drivelicense = db.Column(db.Text)
    created = db.Column(db.DateTime, index=False, unique=False, default=datetime.utcnow)
    

    def __repr__(self):
        return f'<User id:{self.id}, email:{self.email}>'


class EWI_info(db.Model):
    """Data model for users info."""

    __tablename__ = 'ewi_info'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    uid = db.Column(db.Integer, index=True, nullable=False)
    name = db.Column(db.Text) 
    profession = db.Column(db.Text)
    start = db.Column(db.Date)
    finish = db.Column(db.Date)
    info = db.Column(db.String(10))
    

    def __repr__(self):
        return f'<User id:{self.uid}, email:{self.name}>'


class Skill_info(db.Model):
    """Data model for users skills."""

    __tablename__ = 'skill_info'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    uid = db.Column(db.Integer, index=True, nullable=False)
    skill = db.Column(db.Text) 
    level = db.Column(db.Text)
    info = db.Column(db.String(10))
    

    def __repr__(self):
        return f'<User id:{self.uid}, email:{self.skill}>'