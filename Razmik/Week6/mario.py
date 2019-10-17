#!/usr/bin/python3.7
n = ""
while type(n) is str:
    n = input("Height: ")
    if n.isnumeric() and (int(n) <= 8 and int(n) > 0):
        n = int(n)
for i in range(1, n + 1):
    print(" " * (n - i) + "#" * i + "  " + "#" * i)