# Write a Python script that takes input from the user and displays 
# that input back in upper and lower cases.
st = input("Enter the string with lower and upper characters: ")
s = ""
for i in st:
    if i.islower():
        s += i.upper()
    else:
        s += i.lower()
print(s)
print(st.upper())
print(st.lower())