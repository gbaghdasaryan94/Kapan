# Given an array of strings. Find the strings with maximum and minimum lengths in array. 
# Print the sum of their lengths.

arr = ["anymore", "raven", "me", "communicate"]

mi = min([len(i) for i in arr])
ma = max([len(i) for i in arr])

print(mi + ma)