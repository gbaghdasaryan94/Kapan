# Given a positive number, convert the number into corresponding excel column name.
n = int(input("Enter positive number: "))
st = ""
while n > 0:
    tmp = (n - 1) % 26
    st += chr(tmp + 65)
    n = (n - 1) // 26
print("".join(reversed(st)))