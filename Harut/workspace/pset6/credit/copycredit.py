from cs50 import get_int, get_string

while True:
    c = get_string('Credit Card: ')
    if c.isdigit():
        break

s = 0

for i in reversed(range(0, len(c), 2)):
    t = int(c[i+1])
    t2 = int(c[i]) * 2

    if t2 > 9:
        t2 = t2 // 10 + t2 % 10

    s += t + t2

if (s % 10 == 0) and (len(c) == 15) and (c[:2] == '34' or c[:2] == '37'):
    print('AMEX')

elif (s % 10 == 0) and (len(c) == 16) and (c[:2] == '51' or c[:2] == '52' or c[:2] == '53' or c[:2] == '54' or c[:2] == '55'):
    print('MASTERCARD')

elif (s % 10 == 0) and ((len(c) == 13) or (len(c) == 16)) and (c[0] == '4'):
    print('VISA')

else:
    print('INVALID')