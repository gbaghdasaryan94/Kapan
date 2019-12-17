s = input('enter a string: ')
ns = ''

for i in s:
    if i == s[0]:
        ns += '$'
    else:
        ns += i

l = list(ns)
l[0] = s[0]
ns = ''.join(l)
print(f'new string is: {ns}')
