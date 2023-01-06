# TODO
from cs50 import get_float

#Ask how many coins the customer is owed
while True:
    change_dollars = get_float("Enter change owed ")
    if dollars < 0:
        print("Error, invalid amount")
        continue
    else:
        cents = change_dollars * 100
        break

coins = 0

#Calculate the number of quarters to give the customer
while cents >= 25:
    cents = cents - 25
    coins = coins + 1

#Calculate the number of dimes to give the customer
while cents >= 10:
    cents = cents - 10
    coins = coins + 1

#Calculate the number of nickels to give the customer
while cents >= 5:
    cents = cents - 5
    coins = coins + 1

#Calculate the number of pennies to give the customer
while cents >= 1:
    cents = cents - 1
    coins = coins + 1

#Print total number of coins to give the customer
print(coins)