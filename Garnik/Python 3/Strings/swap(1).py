string1 = input("Enter 1st string: ")
string2 = input("Enter 2nd string: ")

out1 = string2[0:2] + string1[2:]
out2 = string1[0:2] + string2[2:]
print(out1, out2)