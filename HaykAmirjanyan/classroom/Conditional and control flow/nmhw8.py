# Write a Python program which accepts a sequence of comma separated
# 4 digit binary numbers as its input and print the numbers that are 
# divisible by 5 in a comma separated sequence
li = ["0100", "0011", "1010", "1001", "1100", "1001", "0101"]
l = ""
for item in li:
    if int(item,2) % 5 == 0:
        l += item + " "
print(l) 
