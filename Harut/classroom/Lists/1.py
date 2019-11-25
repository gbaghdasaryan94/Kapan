n = int(input('number of elements: '))
l = []

for i in range(n):
    el = int(input(f'el[{i}] = '))
    l.append(el)
    
s = 0

for i in l:
    s += i

print(f'sum of el. is: {s}')
