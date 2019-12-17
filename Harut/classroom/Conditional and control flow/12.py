n = input('enter a string: ')

if all(n[i] in '0123456789' for i in range(len(n))):
    print('The string is an integer')
elif n[0] in '+-' and all(n[i] in '0123456789' for i in range(1, len(n))):
        print('The string is an integer')
else:
    print('The string is not an integer')
