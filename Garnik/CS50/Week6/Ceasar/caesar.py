from cs50 import get_string
from sys import argv

if len(argv) != 2:
    print("Usage: python [file] [key]")
    exit(1)

word = get_string("Please enter a word: ")
x = argv[1]
print("ciphertext: ", end="")

for i in word:
    if i.isalpha():
        i = chr(ord(i) + (int(x) % 26))
        if (not i.islower()) and (not i.isupper()):
            i = chr(ord(i)-26)

    print(i, end="")

print()