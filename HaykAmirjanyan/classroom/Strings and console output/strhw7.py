# Write a Python program to remove the characters which have odd index values of a given string.
a = input("Enter the string: ")
b = ""
for i in range(len(a)):
    if(i % 2 == 0):
        b += a[i]
print(b)