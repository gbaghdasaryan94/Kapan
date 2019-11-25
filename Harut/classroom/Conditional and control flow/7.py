row = int(input('enter the number of rows: '))
col = int(input('enter the numbers of colimns: '))
a = [[0 for c in range(col)] for r in range(row)]

for r in range(row):
    for c in range(col):
        a[r][c] = r * c 

print(a)
