s = input('enter a string: ')

if s == s[::-1]:
    print('True')
    quit()
else:
    for i in range(1, len(s)):
        ns = s[-i:] + s[:-i]
        if ns == ns[::-1]:
            print('True')
            quit()
print('False')
