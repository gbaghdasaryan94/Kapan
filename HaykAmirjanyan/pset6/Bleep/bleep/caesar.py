from cs50 import get_string
from sys import argv
import sys
if len(sys.argv) > 1:
    n = int(argv[1])
else:
    print("no key")
    exit(1)
if n < 0:
    print("Write positive number please: ")
    exit(1)

sentance = get_string("Write a sentance: ")
if n > 26:
    n = n % 26
outsentance = ""
for i in range(len(sentance)):
    m = ord(sentance[i])
    if sentance[i].isalpha():
        m += n
        if (sentance[i].isupper() and m > 90) or (sentance[i].islower() and m > 122):
            m -= 26
    outsentance += chr(m)
print("ciphertext:" + outsentance)