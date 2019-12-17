# Given a number. Write a recursive function that reverse the number. Return the new number.

def func(n):
    if n > 9:
        return str(n % 10) + func(n // 10)
    else:
        return str(n)

n = int(input("Enter number: "))
print(n,func(n))