from cs50 import get_float, get_int

while True:
    coins = get_float("Change Owed: ")
    if coins > 0:
        break

cents = round(coins * 100)

q = 0

# 25, 10, 5, 1
q = q + cents // 25
cents = cents % 25
q = q + cents // 10
cents = cents % 10
q = q + cents // 5
cents = cents % 5
q = q + cents
print(q)