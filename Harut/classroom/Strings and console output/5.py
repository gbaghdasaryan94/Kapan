s = input('enter a string: ')
ns = ''

if len(s) < 3:
    ns = s
elif s[-3:] == 'ing':
    ns = s[:-3] + 'ly'
else:
    ns = s + 'ing'

print(f'new string is: {ns}')
