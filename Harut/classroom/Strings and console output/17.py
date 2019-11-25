s1 = input('s1 = ')
s2 = input('s2 = ')

if s1 == s2:
    print('the strings are the same')
    quit()

for i in range(1, len(s2)):
    ns = s2[-i:] + s2[:-i]
    if s1 == ns or s1 == ns[::-1]:
        print('True')
        quit()

print('False')
