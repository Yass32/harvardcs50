# TODO
while True:
    # Check if user input is a positive integer no greater than 8
    height = int(input("Enter half pyramid height: "))
    height = height.isdigit()
    if (1 <= height <= 8):
        break
    else:
        # Reprompt if user gives wrong input
        print("Error, positive integer between 1 and 8, inclusive.")
        continue

# Print out the pyramid
for i in range(height):
    print(" " * (height - 1 - i) + "#" * (i + 1))