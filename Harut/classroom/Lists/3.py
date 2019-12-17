n = int(input('number of elements: '))
l = []

for i in range(n):
    el = int(input(f'e[{i}] = '))
    l.append(el)

max = l[0]

for i in l:
    if i > max:
        max = i

print(f'max = {max}') 
