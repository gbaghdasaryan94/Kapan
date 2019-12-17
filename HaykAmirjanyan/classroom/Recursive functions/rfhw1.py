# Write a recursive function to determine whether all digits of the number are odd or not.

def func(n):
    if n > 9:
        if n % 2 == 0:
            return False
        else:
            return func(n // 10)
    else:
        return n % 2 == 1

n = int(input("Enter int number: "))
print(func(n))