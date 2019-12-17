from cs50 import get_string
from sys import argv
import sys

if len(argv) != 2:
    print("Usage: python bleep.py dictionary")
    exit(1)
word = open(argv[1], 'r').read().split('\n')
message = get_string("What message would you like to censor? \n")
message = message.split(" ")
for key in message:
    keyword = key.lower()
    if keyword in word:
        print("*" * len(keyword) + " ", end="")
    else:
        print(key + " ", end="")
print('')