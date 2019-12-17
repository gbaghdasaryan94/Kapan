l = [1, '10', 'hi', 2, 3]
ln = []
ls = []

for i in l:
    if type(i) in (int, float):
        ln.append(i)
    elif type(i) == str:
        ls.append(i)

print(f'numbers: {len(ln)}')
print(f'strings: {len(ls)}')
