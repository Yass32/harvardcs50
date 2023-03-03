import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

entries = db.execute("SELECT * FROM db")


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

        ##Add to database
        entries = db.execute("INSERT ")


        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        db.execute("SELECT * FROM db")
        return render_template("index.html")


