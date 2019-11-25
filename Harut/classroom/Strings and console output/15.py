s = input('enter a string: ')

ns = ''
for i in s:
    if i not in ns:
        ns += i

print(f'new string is: {ns}')
