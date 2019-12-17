# Given a number. Write a function that calculates its sum of the digits and if that sum 
# has more than 1 digit find the sum of digits of that number. 
# Repeat that process if needed and return the result.

def func(n):
    if n > 9:
        return func(func(n // 10) + n % 10)
    else:
        return n

n = int(input("Enter int number: "))
print(func(n))