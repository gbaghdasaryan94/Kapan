from cs50 import get_float
from math import floor
money = -1.0
while money < 0:
    money = get_float("Give me my money! ")
money = round(money * 100)
count = floor(money / 25) + floor((money % 25) / 10) + floor(((money % 25) %
                                                              10) / 5) + floor((((money % 25) % 10) % 5) / 3) + (((money % 25) % 10) % 5) % 3
print(count)
