#!/usr/bin/python3.7
from sys import argv, exit
if len(argv) != 2:
    exit("Enter valid")
if not argv[1].isalpha():
    exit("Enter valid")
key = [ord(i) % 32 - 1 for i in argv[1]]
a = input("plaintext:  ")
j = 0
print("ciphertext: ", end='')
for char in a:
    if char.isalpha():
        char = chr(ord(char) // 32 * 32 + (ord(char) % 32 + key[j % len(key)]) % 26)
        j += 1
    print(char, end='')
print()