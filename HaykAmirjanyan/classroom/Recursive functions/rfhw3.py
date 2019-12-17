# Given a positive number. Write a recursive function that returns its factorial. 
# ( n! = n * (n-1) * (n-2) * … * 3 * 2 * 1 , 0! = 1 )

def func(n):
    if n > 0:
        return n * func(n - 1)
    else:
        return 1

n = int(input("Enter int number: "))
print(func(n))