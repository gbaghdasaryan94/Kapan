# 1. Write a Python program to find those numbers which are divisible by 7 and multiple of 5, 
# between 1500 and 2700 (both included).

for i in range(1500, 2701, 5):
    if i%7 == 0:
        print(i)