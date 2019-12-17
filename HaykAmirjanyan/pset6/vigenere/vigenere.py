import sys
from sys import argv
from cs50 import get_string

if len(sys.argv) > 1:
    key = argv[1]
else:
    print("enter the key:")
    exit(1)

for i in range(len(key)):
    if not key[i].isalpha():
        print("Enter a valid key")
        exit(1)

key = key.upper()
sentance = get_string("Wriite a sentance: ")
j = 0
out_sentance = ""

for l in range(len(sentance)):
    m = ord(sentance[l])
    if sentance[l].isalpha():
        m = ord(sentance[l]) + ord(key[j]) - 65
        j += 1
    if j == len(key):
        j = 0
    if (sentance[l].islower() and m > 122) or (sentance[l].isupper() and m > 90):
        m -= 26
    out_sentance += chr(m)
print("ciphertext:" + out_sentance)