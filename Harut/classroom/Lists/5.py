n = int(input('number of el: '))
l = []

for i in range(n):
    el = int(input(f'el[{i}] = '))
    l.append(el)

nl = []

for i in range(len(l) - 1):
    nl.append(l[i] * l[i + 1])

print(nl)
