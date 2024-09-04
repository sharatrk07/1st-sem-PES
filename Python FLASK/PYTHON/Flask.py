from flask import Flask, render_template, redirect, request
from flask_wtf import FlaskForm
from wtforms import *
from wtforms.validators import DataRequired
from flask_bootstrap import Bootstrap
from flask_sqlalchemy import SQLAlchemy

app = Flask(_name_)
bootstrap = Bootstrap(app)
app.config['SECRET_KEY'] = 'Secret@123'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///library.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

class Author(db.Model):
    aid = db.Column(db.Integer,primary_key = True)
    authname = db.Column(db.String(50),nullable=False)
    books = db.relationship('Book',backref='Author',lazy=True,cascade="all, delete-orphan")

class Book(db.Model):
    bid = db.Column(db.Integer,primary_key = True)
    bookname= db.Column(db.String(50),nullable=False)
    auth_id = db.Column(db.Integer,db.ForeignKey('author.aid'),nullable=False)

@app.route("/")
def index():
    authors = Author.query.all()
    return render_template('index2.html',authors=authors)

@app.route("/addauth",methods=['POST'])
def addauth():
    auth_name = request.form['AuthName']
    new_row = Author(authname=auth_name)
    db.session.add(new_row)
    db.session.commit()
    return redirect('/')

@app.route('/addbook/<int:aid>',methods=['POST'])
def addbook(aid):
    title = request.form['Title']
    aut = Author.query.get(aid)
    if aut:
        new_row = Book(bookname = title, auth_id = aid)
        db.session.add(new_row)
        db.session.commit()
    return redirect('/')

with app.app_context():
    db.create_all()

app.run()