# TODO
while True:
    height = int(input("Enter half pyramid height: "))
    if (1 <= height <= 8) :
        break
    else:
        print("Error, positive integer between 1 and 8, inclusive.")
        continue


for i in range(height):
    print()

"""
i = 0

while i < height:
    j = i
    while j <= i:
        print("#")
        j = j + 1
    i = i + 1
"""