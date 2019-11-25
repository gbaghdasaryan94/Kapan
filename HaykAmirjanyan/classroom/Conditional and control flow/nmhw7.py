# Write a Python program which takes two digits m (row) and n (column) 
# as input and generates a two-dimensional array. 
# The element value in the i-th row and j-th column of the array should be i*j.
n = int(input("Input number of rows: "))
m = int(input("Input number of columns: "))
print([[i*j for j in range(m)] for i in range(n)])
