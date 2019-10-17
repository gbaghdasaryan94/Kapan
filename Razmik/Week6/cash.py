#!/usr/bin/python3.7
n = ""
while type(n) is str:
    n = input("Change owed: ")
    try:
        if (float(n) * 100) // 1 > 0:
            n = int((float(n) * 100))
    except ValueError:
        continue
print(n // 25 + n % 25 // 10 + n % 25 % 10 // 5 + n % 25 % 10 % 5)