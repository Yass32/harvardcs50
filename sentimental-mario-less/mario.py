# TODO
size = input("Enter half pyramid height: ")
while True:
    if (1 <= size <= 8) :
        height = int(size)
        print(height)
        break
    else:
        print("Error, positive integer between 1 and 8, inclusive.")
        continue