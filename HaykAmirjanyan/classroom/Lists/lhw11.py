# Given an array consisting from the arrays of numbers (like a two-dimensional array). 
# Find sum of each row and print them as an array.

arr = [[3, 4, 5], [1, 0, 0], [4, 5, 4], [8, 8, -1]]
print([sum(i) for i in arr])