#  Write a Python program that prints all the numbers from 0 to 6 except 3 and 6.
st  = ""
for i in range(6):
    if i != 3:
        st += str(i) + " "   
print(st)
