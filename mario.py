from cs50 import get_int

height = get_int("Height: ")

if height < 0 or height > 8:
    exit()

for i in range(height):
    string = ' ' * (height - i)

    string += (i + 1) * '#'
    print(string[1:])
