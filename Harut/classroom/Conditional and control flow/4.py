n = 1, 2, 3, 4, 5, 6, 7, 8, 9
e = 0
o = 0

for i in n:
    if i % 2 == 0:
        e += 1
    else:
        o += 1
    
print(f'number of evens is: {e}')
print(f'number of odds is: {o}')
