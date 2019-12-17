# Given N number. Write a recursive function that should print from 1 to N numbers.

def func(n):
    if n > 1:
        return  str(func(n - 1)) + "," +  str(n) 
    else:
        return 1

n = int(input("Enter int number: "))
print(str(n) + " " + func(n))