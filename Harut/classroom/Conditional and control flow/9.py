s = input('enter a string: ')
l = 0
d = 0

for i in s:
    if i.isalpha():
        l += 1
    elif i.isdigit():
        d += 1

print(f'number of letters is: {l}')
print(f'number of digits is: {d}')
