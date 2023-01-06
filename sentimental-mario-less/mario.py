# TODO
while True:
    height = int(input("Enter half pyramid height: "))
    if (1 <= height <= 8) :
        break
    else:
        print("Error, positive integer between 1 and 8, inclusive.")
        continue

for i in range(height):
    print(" " * (height - 1 - i), "#" * (i + 1), end="#")





"""
for x in range (height):
    print((height-x - 1)*' ' + (x+1)*'#')

for i in range(height):
    for j in range(i + 1):
        print(" " * space, "#" * i)
        space = space - 1


i = 0

while i < height:
    j = i
    while j <= i:
        print("#")
        j = j + 1
    i = i + 1

for i in range(height):
    for j in range(i + 1):
        print(" " * space, "#" * i)
"""