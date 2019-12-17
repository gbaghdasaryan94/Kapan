# Write a Python program that accepts a string and calculate the number of digits and letters.
st = input("Input string: ")
a,b = 0,0
for i in st:
    if i.isalpha():
        a += 1
    elif i.isdigit():
        b += 1
    else:
        pass
print("Letters",a)
print("Digits",b)
