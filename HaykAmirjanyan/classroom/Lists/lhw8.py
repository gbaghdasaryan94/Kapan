# Given an array of strings and numbers. 
# Print the number of integers and the number of strings in the array.

arr = [1, '10', 'hi', 2, 3]
n,s = 0,0
for i in arr:
    if type(i) is int:
        n += 1
    elif type(i) is str:
        s += 1
print("Numbers: " + str(n) + ",  Strings: " + str(s))