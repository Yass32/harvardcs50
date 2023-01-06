# TODO
from cs50 import get_float

#Define the funcctions
def calculate_quarters(dollars):
    return (dollars * 100) / 25.0

def calculate_dimes(dollars):
    return (dollars * 100) / 10.0

def calculate_nickels(dollars):
    return (dollars * 100) / 5.0

def calculate_pennies(dollars):
    return (dollars * 100) / 1.0

#Ask how many dollars the customer is owed
while True:
    dollars = get_float("Enter change owed ")
    if dollars < 0:
        print("Error, invalid amount")
        continue
    else:
        break

#Calculate the number of quarters to give the customer
quart = calculate_quarters(dollars)
dollars = dollars - quart * 25.0

#Calculate the number of dimes to give the customer
dimes = calculate_dimes(dollars)
dollars = dollars - dimes * 10.0

#Calculate the number of nickels to give the customer
nickels = calculate_nickels(dollars)
dollars = dollars - nickels * 5.0

#Calculate the number of pennies to give the customer
pennies = calculate_pennies(dollars)
dollars = dollars - pennies * 1.0

#The minimum number of coins
coins = quart + dimes + nickels + pennies

#Print total number of coins to give the customer
print(f"{coins}")


