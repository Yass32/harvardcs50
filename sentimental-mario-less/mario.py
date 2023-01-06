# TODO
size = input("Enter half pyramid height: ")
height = int(size)
while True:
    if (1 <= height <= 8) :
        break
    else:
        print("Error, positive integer between 1 and 8, inclusive.")
        continue

i = 0
j = i
while i < height:
    while j <= i:
        print("#")
        j = j + 1
    i = i + 1