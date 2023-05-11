import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


#users = db.execute("SELECT * FROM users")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == GET:
        return render_template("buystock.html")
    else:
        symbol = request.form.get("symbol")
        if not symbol or 
        shares = request.form.get("shares")

    return apology("TODO")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")

        #If lookup is successful, name, price and symbol is returned else apologize
        stock = lookup(symbol)
        if not stock:
            return apology("Stock does not exist")
        else:
            return render_template("quoted.html", name = stock["name"], price = stock["price"], symbol = stock["symbol"])





@app.route("/register", methods=["GET", "POST"])
def register():

    """Register user"""
    ##Forget any user id
    session.clear()

    ##Get info from form
    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    ##When requested via GET display registration form
    if request.method == "GET":
        return render_template("registration.html")

    ##When requested via POST, check for errors
    else:
        '''
        if username == "" or len(db.execute('SELECT username FROM users WHERE username = ?', username)) > 0:
            return apology("Invalid Username")

        if password == "" or password != confirmation:
            return apology("Invalid Password")

        try:
            # Add new user to users db (includes: username and HASH of password)
            #
            db.execute('INSERT INTO users (username, hash) VALUES(?, ?)', username, generate_password_hash(password))

            # Query database for username
            #
            rows = db.execute("SELECT * FROM users WHERE username = ?", username)

            # Remember user that has logged in
            #
            session["user_id"] = rows[0]["id"]

            # Redirect user to home page
            #
            return redirect("/")
        except:
            return apology('Username has already been registered')
            '''




        ##If any field is blank return apology
        if not username:
            return apology("Username Missing")
        elif not password:
            return apology("Password Missing")

        ##If password and confirmation doesn't match retunr apology
        if password != confirmation:
            return apology("Password Error")



        ##Query database to see if username is already taken
        if len(db.execute("SELECT * FROM users WHERE username = ?", username)) > 0:
            return apology("Username Taken")


        #For security generate a hash of user password
        hash = generate_password_hash(password)

        ##insert new user into users table
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)

        ##Log user in
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        session["user_id"] = rows[0]["id"]

        #Redirect user to homepage


        return render_template("login.html")
        return redirect("/")
        login()




@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
