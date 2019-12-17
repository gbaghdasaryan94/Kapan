#!/usr/bin/python3.7
import sys
if len(sys.argv) != 2:
    sys.exit("Enter valid")
if not sys.argv[1].isnumeric():
    sys.exit("Enter valid")
key = int(sys.argv[1]) % 26
a = input("plaintext:  ")
b = ""
for char in a:
    b += chr(ord(char) // 32 * 32 + (ord(char) % 32 + key) % 26) if char.isalpha() else char
print("ciphertext: " + b)