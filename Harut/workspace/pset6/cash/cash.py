from cs50 import get_float

while True:
    d = get_float("$ = ")
    if (d > 0):
        break

c = d * 100
q = c // 25 + c % 25 // 10 + c % 25 % 10 // 5 + c % 25 % 10 % 5 // 1
print(q)