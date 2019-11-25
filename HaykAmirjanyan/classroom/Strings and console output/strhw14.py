# Write a Python program to check if a string contains all letters of the alphabet.

# import string
# st = input("ENter long word: ")
# st1 = set(string.ascii_lowercase)
# print(set(st.lower()) >= st1)
st = input("Enter string: ")
st1 = ""
for i in st:
    if i.isalpha() and i not in st1:
        st1 += i.lower()
print(len(st1) == 26)