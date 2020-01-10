# 3. Given a positive number. Write a recursive function that returns its factorial.
#  ( n! = n * (n-1) * (n-2) * … * 3 * 2 * 1 , 0! = 1 )



number = abs(int(input("Please enter a mumber: ")))

def factorial(n):
    if n < 2:
        return 1
    else:
        return n * factorial(n-1)    

print(factorial(number))        