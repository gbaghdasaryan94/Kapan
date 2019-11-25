# Write a Python program to get the Fibonacci series between 0 to 50
a,b = 0,1
st = ""
while b <= 50:
    st += str(b) + " "
    a,b = b,a + b
print(st)

