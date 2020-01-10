# 5. Write a Python program that prints all the numbers from 0 to 6 except 3 and 6.

for numbers in range(0,7):
    if numbers > 0 and numbers%3 == 0:
        continue
    print(numbers)
