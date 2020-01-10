# 7. Write a Python program which takes two digits m (row) and n (column) as input and generates a two-dimensional array. The element value in the i-th row and j-th column of the array should be i*j.


row, column = 3,4
matrix = []

for i in range (row):
    matrix.append([])
    for j in range(column):
        matrix[i].append(i*j)
print(matrix)
