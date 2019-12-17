n = int(input('number of el: '))
l = []
l1 = []
l2 = []

for i in range(n):
    el = input(f'el[{i}] = ')
    l.append(el)

for i in l:
    if i.isnumeric():
        if int(i) % 2 != 0:
            l1.append(int(i))
        elif int(i) % 2 == 0:
            l2.append(int(i))

print(l1 + l2)
