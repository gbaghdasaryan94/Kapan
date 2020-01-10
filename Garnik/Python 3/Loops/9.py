# 9. Write a Python program that accepts a string and calculate the number of digits and letters.

string = 'Python 3.2'.split()
alpha = 0
count = 0
for i in string:
    for j in i :
        if j.isalpha():
            alpha +=1
        elif j.isdigit():
            count+=1
print("Letters:",alpha,"\n" "Digits:", count)
