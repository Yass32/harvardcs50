# TODO
import cs50
while True:
    change = get_float("Enter change owed ")
    if change < 0:
        print("Error, invalid amount")
        continue
    else:
        break
