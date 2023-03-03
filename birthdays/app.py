import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

ENTRIES = db.execute("SELECT * FROM birthdays")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        ##Data gotten from user submitting form
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        '''name = db.execute("SELECT name FROM birthdays")
        month = db.execute("SELECT month FROM birthdays")
        day = db.execute("SELECT day FROM birthdays")'''
        birthday = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthday=birthday) #name=name, month=month, day=day)


