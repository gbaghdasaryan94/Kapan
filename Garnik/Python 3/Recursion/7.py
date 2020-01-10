# 7. Given a number. Write a recursive function that reverse the number. Return the new number.


number = str(abs(int(input("Please enter a positive number: "))))

def reverse_number(n):
    if n == n[::-1]:
        return n
    else:
        return str(int(n)%10) + str(reverse_number(str(int(n)//10)))    


print(reverse_number(number))        