# Write a Python program to create the multiplication table (from 1 to 10) of a number.
n = int(input("Enter number between 1 to 9: "))
for i in range(1,11):
    print(n,"x",i,"=",i * n)