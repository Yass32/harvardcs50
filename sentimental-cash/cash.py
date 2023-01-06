# TODO
import cs50

def calculate_quarters(dollars):
    return (dollars * 100) / 25

def calculate_dimes(dollars):
    return (dollars * 100) / 10

def calculate_nickels(dollars):
    return (dollars * 100) / 5

def calculate_pennies(dollars):
    return (dollars * 100) / 1

while True:
    dollars = cs50.get_float("Enter change owed ")
    if change < 0:
        print("Error, invalid amount")
        continue
    else:
        break


d


