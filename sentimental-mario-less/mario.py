# TODO
while True:
    height = int(input("Enter half pyramid height: "))
    if (type(height) == int and 1 <= height <= 8) :
        break
    else:
        print("Error, positive integer between 1 and 8, inclusive.")
        continue

for i in range(height):
    print(" " * (height - 1 - i) + "#" * (i + 1))