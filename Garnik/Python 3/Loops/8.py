# 8. Write a Python program which accepts a sequence of comma separated 4 digit binary numbers as its input 
# and print the numbers that are divisible by 5 in a comma separated sequence

binary = '0011,1100,0010,1010,1111,0101'.split(',')
string = []
for i in binary:
    if int(i,2)%5==0:
        string.append(i)
print(','.join(string))

