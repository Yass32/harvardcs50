# TODO
from cs50 import get_float

#Define the funcctions
def calculate_quarters(dollars):
    return int((dollars * 100) // 25)

def calculate_dimes(dollars):
    return int((dollars * 100) // 10)

def calculate_nickels(dollars):
    return int((dollars * 100) // 5)

def calculate_pennies(dollars):
    return int((dollars * 100) // 1)

#Ask how many dollars the customer is owed
while True:
    dollars = get_float("Enter change owed ")
    if dollars < 0:
        print("Error, invalid amount")
        continue
    else:
        break

#Calculate the number of quarters to give the customer
quart = int(calculate_quarters(dollars))
dollars = dollars - quart * 25

#Calculate the number of dimes to give the customer
dimes = int(calculate_dimes(dollars))
dollars = dollars - dimes * 10

#Calculate the number of nickels to give the customer
nickels = int(calculate_nickels(dollars))
dollars = dollars - nickels * 5

#Calculate the number of pennies to give the customer
pennies = int(calculate_pennies(dollars))
dollars = dollars - pennies * 1

#The minimum number of coins
coins = int(quart + dimes + nickels + pennies)

#Print total number of coins to give the customer
print(coins)


