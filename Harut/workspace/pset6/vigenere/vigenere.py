from cs50 import get_string
from sys import argv


def alpha(cc):
    if cc.islower():
        return ord(cc) - 97
    elif cc.isupper():
        return ord(cc) - 65


k = argv[1]

if not k.isalpha():
    exit("key must be only alphabetical")

n = 0
ct = ''

if len(argv) != 2:
    print("Usage: ./vigenere keyword")
    exit(1)

pt = get_string("plaintext: ")

for c in pt:
    if c.isupper():
        ct += chr((alpha(c) + alpha(k[n])) % 26 + 65)
        n += 1

    elif c.islower():
        ct += chr((alpha(c) + alpha(k[n])) % 26 + 97)
        n += 1

    else:
        ct += c

    if n == len(k):
        n = 0

print(f'ciphertext: {ct}')