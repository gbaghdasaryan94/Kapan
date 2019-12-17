from cs50 import get_string
from sys import argv

def alpha(cc):
    if cc.islower():
        return ord(cc) - 97
    elif cc.isupper():
        return ord(cc) - 65


k = int(argv[1])
pt = get_string("enter plaintext: ")
ct = ''

for c in pt:
    if c.isupper():
        ct += chr((alpha(c) + k) % 26 + 65)

    elif c.islower():
        ct += chr((alpha(c) + k) % 26 + 97)

    else:
        ct += c

print(f'ciphertext: {ct}')