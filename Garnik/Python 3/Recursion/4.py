# 4. Given an integer. Write a recursive function that returns n-th element in the Fibonacci sequence.


def fibonacci(n):
    if n < 3:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)    

print(fibonacci(abs(int(input("Please enter a number: ")))))        



