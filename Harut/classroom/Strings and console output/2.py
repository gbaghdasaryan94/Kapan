s = input('enter a string: ')

if len(s) < 2:
    s = ''
else:
    s = s[:2] + s[-2:]

print(f'new string is: {s}')
