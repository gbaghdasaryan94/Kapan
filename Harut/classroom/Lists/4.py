n = int(input('number of el. : '))
l = []

for i in range(n):
    el = input(f'e[{i}] = ')
    l.append(el)

s = ''

for i in l:
    s += i

print(s)
