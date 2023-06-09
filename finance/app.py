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
    # Remeber user logged in
    current_user = session["user_id"]
    # Display user's current cash balance
    cash = db.execute("SELECT * FROM users WHERE id = ?", current_user)
    if not cash:
        return apology("No cash")
    user_cash = cash[0]["cash"]
    portfolio = db.execute(
        "SELECT symbol, stocks, price, total, SUM(shares) as total_shares FROM portfolio WHERE username_id = ? GROUP BY symbol", current_user)

    # Total value of stocks and cash together
    balance = user_cash
    for port in portfolio:
        balance += port["total"]

    return render_template("index.html", portfolio=portfolio, cash=user_cash, balance=balance)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # When form requested via GET, displayform to buy a stock
    if request.method == "GET":
        return render_template("buystock.html")
    else:
        # When form is submitted via POST, purchase the stock as long as user can afford it
        symbol = request.form.get("symbol")
        stock = lookup(symbol)

        # Check for valid input
        if not symbol or stock is None:
            return apology("Symbol error")

        try:
            shares = int(request.form.get("shares"))
        except:
            return apology("Shares is not an integer")

        if shares <= 0:
            return apology("Shares Error")

        stocks = stock["name"]
        price = stock["price"]
        total = price * shares

        # Remember user logged in
        current_user = session["user_id"]
        cash = db.execute("SELECT cash FROM users where id = ?", current_user)
        user_cash = cash[0]["cash"]

        # Ensure user have enough cash to afford the stock
        if user_cash < total:
            return apology("Insufficient cash")
        else:
            # Run SQL statement on database to purchase stoch and update cask to reflect purchased stock
            updated_cash = user_cash - total
            db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_cash, current_user)
            db.execute("INSERT INTO portfolio (symbol, stocks, shares, price, total, username_id) VALUES (?, ?, ?, ?, ?, ?)",
                       symbol, stocks, shares, price, total, current_user)

            # Record the history
            db.execute("INSERT INTO history (username_id, symbol, transaction_type, shares, price) VALUES (?, ?, ?, ?, ?)",
                       current_user, symbol, "buy", shares, price)
            flash('You have bought your stocks successfully.', 'success')
            return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Remeber user logged in
    current_user = session["user_id"]

    # Display all of a user’s transactions ever, listing row by row each and every buy and every sell
    history_transactions = db.execute(
        "SELECT symbol, transaction_type, shares, price, history FROM history WHERE username_id = ?", current_user)
    if not history:
        return apology("No history")

    return render_template("history.html", history_transactions=history_transactions)


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

        flash('You have logged in successfully.', 'success')

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
    # When form is requested via GET, display form to request a stock quote
    if request.method == "GET":
        return render_template("quote.html")
    else:
        # When requested via POST lookup up the stock symbol by calling lookup() and displauy results
        symbol = request.form.get("symbol")
        stock = lookup(symbol)

        # If lookup is successful, a dictionary of stock name, price and symbol is returned else apologize
        if stock is None:
            return apology("Stock does not exist")
        else:
            return render_template("quoted.html", name=stock["name"], symbol=stock["symbol"], price=stock["price"])


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Forget any user id
    session.clear()

    # Get info from form
    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    # When requested via GET display registration form
    if request.method == "GET":
        return render_template("registration.html")

    # When requested via POST, check for errors
    else:

        # If any field is blank return apology
        if not username or not password:
            return apology("Username Error")
        # If password and confirmation doesn't match return apology
        if password != confirmation:
            return apology("Password Error")

        # For security generate a hash of user password
        hash = generate_password_hash(password)

        # insert new user into users table
        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)

            # Log user in
            rows = db.execute("SELECT * FROM users WHERE username = ?", username)
            session["user_id"] = rows[0]["id"]

            flash('You have registered successfully.', 'success')

            # Redirect user to homepage
            return redirect("/")
        except:
            # If username is already taken return an apology
            return apology("Username is taken")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # Remember which user has logged in
    current_user = session["user_id"]

    portfolio = db.execute("SELECT symbol, shares FROM portfolio WHERE username_id = ?", current_user)

    # When requested via GET display selling form
    if request.method == "GET":
        return render_template("sell.html", portfolio=portfolio)
    else:
        # When form is submitted via POST
        symbol = request.form.get("symbol")
        try:
            shares = int(request.form.get("shares"))
        except:
            return apology("Shares should be an INTEGER")

        # Check if shares is a valid number and user has the required amount
        user_shares = db.execute("SELECT shares FROM portfolio WHERE username_id = ?", current_user)
        if shares <= 0 or user_shares[0]["shares"] < shares:
            return apology("Shares error")

        cash = db.execute("SELECT cash FROM users WHERE id = ?", current_user)
        cash = cash[0]["cash"]

        # Check if requested stock is valid
        stock = lookup(symbol)
        if stock is None:
            return apology("Stock error")

        # Sell specified number of shares of stock
        db.execute("UPDATE portfolio SET shares = ? WHERE username_id = ? AND symbol = ?",
                   portfolio[0]["shares"] - shares, current_user, symbol)

        # Update user's cash
        profit = stock["price"] * shares
        db.execute("UPDATE users SET cash = ? WHERE id = ?", profit + cash, current_user)

        # Record history
        db.execute("INSERT INTO history (username_id, symbol, transaction_type, shares, price) VALUES (?, ?, ?, ?, ?)",
                   current_user, symbol, "sell", shares, stock["price"])

    return redirect("/")


@app.route("/forget", methods=["GET", "POST"])
def forget():
    if request.method == "GET":
        return render_template("forget.html")
    else:
        username = request.form.get("username")
        password = request.form.get("password")
        # Validate the username and password
        if not username or not password:
            return apology("Please fill in all fields")

        try:
            db.execute("UPDATE users SET hash = ? WHERE username = ?", generate_password_hash(password), username)
            flash('Your password has been updated successfully.', 'success')
            return render_template("login.html")
        except:
            return apology("Username does not exist")


@app.route("/change", methods=["GET", "POST"])
def change():
    if request.method == "GET":
        return render_template("change.html")
    else:
        username = request.form.get("username")
        old_password = request.form.get("old_password")
        new_password = request.form.get("new_password")

        # Validate the username, old_password, and new_password
        if not username or not old_password or not new_password:
            return apology("Please fill in all fields")

        # To check if the hash of the old password provided by the user matches the hashed password stored in the database
        row = db.execute("SELECT * FROM users WHERE username = ?", username)
        if not row:
            return apology("Username is incorrect")

        if not check_password_hash(row[0]["hash"], old_password):
            flash('Incorrect current password. Please try again.', 'danger')
            return apology("Password is not correct")

        try:
            db.execute("UPDATE users SET hash = ? WHERE username = ?", generate_password_hash(new_password), username)
            flash('Your password has been updated successfully.', 'success')
            return render_template("login.html")
        except:
            return apology("Username does not exist")


'''
SQL Tables

CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    username TEXT NOT NULL,
    hash TEXT NOT NULL,
    cash NUMERIC NOT NULL DEFAULT 10000.00
);
CREATE TABLE sqlite_sequence(name,seq);
CREATE UNIQUE INDEX username ON users (username);

CREATE TABLE portfolio (
    username_id INTEGER NOT NULL,
    symbol TEXT NOT NULL,
    stocks TEXT NOT NULL,
    shares INTEGER NOT NULL DEFAULT 0,
    price REAL NOT NULL,
    total REAL NOT NULL,
    transaction TEXT NOT NULL,
    date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (username_id) REFERENCES users(id)
    );
CREATE TABLE history (
    username_id INTEGER NOT NULL,
    symbol TEXT NOT NULL,
    transaction_type TEXT NOT NULL,
    shares INTEGER NOT NULL DEFAULT 0,
    price REAL NOT NULL,
    history TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (username_id) REFERENCES users(id)
);
'''