n = int(input('number of el: '))
l = []

for i in range(n):
    el = input(f'el[{i}] = ')
    l.append(el)

max = len(l[0])
min = len(l[0])

for i in l:
    if len(i) > max:
        max = len(i)
    elif len(i) < min:
        min = len(i)
    
print(min + max)
