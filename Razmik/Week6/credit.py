#!/usr/bin/python3.7
n = ""
p = 0
while type(n) is str:
    n = input("Number: ")
    if n.isnumeric():
        n = [int(i) for i in n]
if 13 < len(n) < 16 and len(n) != 14:
    for i in range(len(n)):
        p += n[::-1][i] if not i % 2 else (n[::-1][i] * 2) // 10 + (n[::-1][i] * 2 - ((n[::-1][i] * 2) // 10) * 10)
    if not p % 10 and n[0] == 4:
        exit("VISA\n")
    elif not p % 10 and n[0] == 5 and 1 <= n[1] <= 5:
        exit("MASTERCARD\n")
    elif (n[0] == 3 and (n[1] == 4 or n[1] == 7)):
        exit("AMEX\n")
print("INVALID\n")
