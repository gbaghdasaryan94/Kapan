# 2. Given a number. Write a function that calculates its sum of the digits and 
# if that sum has more than 1 digit find the sum of digits of that number. 
# Repeat that process if needed and return the result.


number = abs(int(input("Please enter a number: ")))

def sum_of_digits(n):
    if n < 10:
        return n
    else:
        return sum_of_digits(n%10 + sum_of_digits(n//10))
      
print(sum_of_digits(number))