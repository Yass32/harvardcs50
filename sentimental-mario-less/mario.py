# TODO
while True:
    height = int(input("Enter half pyramid height: "))
    if (1 <= height <= 8) :
        break
    else:
        print("Error, positive integer between 1 and 8, inclusive.")
        continue

space = height - 1
for i in range(1, height + 1):
    print(" " * space, "#" * i)
    space = space - 1

"""
i = 0

while i < height:
    j = i
    while j <= i:
        print("#")
        j = j + 1
    i = i + 1
"""