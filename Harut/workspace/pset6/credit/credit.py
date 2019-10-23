from cs50 import get_string

while True:
    c = get_string('Credit Card: ')
    if c.isdigit():
        break

s = 0
n = 1

for i in reversed(c):

    if n % 2 != 0:
        s += int(i)
    else:
        if int(i) * 2 < 10:
            s += 2 * int(i)
        else:
            s += (2 * int(i)) // 10 + (2 * int(i)) % 10
    n += 1

if (s % 10 == 0) and (len(c) == 15) and (c[:2] == '34' or c[:2] == '37'):
    print('AMEX')

elif (s % 10 == 0) and (len(c) == 16) and (c[:2] == '51' or c[:2] == '52' or c[:2] == '53' or c[:2] == '54' or c[:2] == '55'):
    print('MASTERCARD')

elif (s % 10 == 0) and ((len(c) == 13) or (len(c) == 16)) and (c[0] == '4'):
    print('VISA')

else:
    print('INVALID')