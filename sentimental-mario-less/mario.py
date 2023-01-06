# TODO
size = input("Enter half pyramid height: ")
height = int(size)
while True:
    if (1 <= height <= 8) :
        break
    else:
        print("Error, positive integer between 1 and 8, inclusive.")
        continue