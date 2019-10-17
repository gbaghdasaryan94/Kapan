#!/usr/bin/python3.7
from crypt import crypt
import sys

if len(sys.argv) != 2:
    sys.exit("Usage: python crack.py hash")
if len(sys.argv[1]) != 13:
    sys.exit("Usage: python crack.py hash")


def nextW(wrd):
    for i in range(len(wrd)):
        wrd[i] = chr(ord(wrd[i]) + 1 if (wrd[i]) != 'Z' else 97)
        if (ord(wrd[i]) > 122):
            wrd[i] = 'A'
            if i + 1 == len(wrd):
                wrd.append("A")
        else:
            break


s = list("A")
hashed = sys.argv[1]
while len(s) < 6:
    print(''.join(s))
    if hashed == crypt(''.join(s), hashed):
        sys.exit(''.join(s))

    else:
        nextW(s)
