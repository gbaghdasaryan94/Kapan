l = ['a', 'b', 'x', 'd']

for n, i  in enumerate(l):
    if i == 'x':
        l[n] = 'q'

print(l)