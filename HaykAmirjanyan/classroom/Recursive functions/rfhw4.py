# Given an integer. Write a recursive function that returns n-th element in the Fibonacci sequence.

def func(n):
    if n < 2:
        return n
    else:
        return func(n - 2) + func(n - 1)

n = int(input("Enter number: "))
print(func(n))
