from cs50 import get_int

height = 0

# prompt the user input if the height is not possitive number
while height < 1 or height > 8:
    height = get_int("Input the height: ")

# print spaces and dashes
for i in range(1, height+1):
    print(" " * (height-i) + "#" * i + "  " + "#" * i)
