n = int(input('enter a number: '))

if n == 26:
    print('Z')
    quit()

if n % 26 == 0:
    print(chr(n // 26 - 2 + ord('A')) + 'Z')
elif n > 26:
    print(chr(n // 26 - 1 + ord('A')) + chr(n % 26 - 1 + ord('A')))
else:
    print(chr(n % 26 - 1 + ord('A')))
