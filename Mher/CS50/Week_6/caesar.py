from sys import argv
from cs50 import get_string

if len(argv) != 2:
    exit()

n = int(argv[1])

if n > 26:
    n %= 26

word = get_string('plaintext: ')

for i in word:
    if i.isupper()