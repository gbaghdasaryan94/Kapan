from cs50 import get_float

coins = 0
while (coins <= 0):
    coins = get_float("Change owed: ") * 100

print(coins // 25 + (coins % 25) // 10 + ((coins % 25) % 10) // 5 + ((coins % 25) % 10) % 5)
