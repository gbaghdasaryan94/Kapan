# Write a Python program to remove duplicate characters of a given string.
st = input("Enter string: ")
st1 = ""
for i in st:
    if i not in st1:
        st1 += i
print(st1)