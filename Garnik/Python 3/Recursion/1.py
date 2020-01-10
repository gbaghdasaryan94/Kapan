# 1. Write a recursive function to determine whether all digits of the number are odd or not.

number = abs(int(input("Enter a number: ")))



def odd(n):
    if n <10:
        return n%2 == 1
    else:
        if n%2 == 0:
            return False
        else:
            return odd(n//10)    

print(odd(number))