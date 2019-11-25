y = int(input('y = '))
m = int(input('m [1-12] = '))
d = int(input('d [1-31] = '))


def leap_year(y):
    if y % 4 == 0:
        if y % 100 == 0:
            if y % 400 == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False


if not leap_year(y) and d < 28:
    d += 1
elif leap_year(y) and d < 29:
    d += 1
elif m != 2 and d < 30:
    d += 1
elif m in (1, 3, 5, 7, 8, 10, 12) and d < 31:
    d += 1
elif not leap_year(y) and m == 2 and d == 28:
    m += 1
    d = 1
elif leap_year(y) and m == 2 and d == 29:
    m += 1
    d = 1
elif m in (4, 6, 9, 11) and d == 30:
    m += 1
    d = 1
elif m in (1, 3, 5, 7, 8, 10) and d == 31:
    m += 1
    d = 1
elif m == 12 and d == 31:
    y += 1
    m = 1
    d = 1
else:
    print('wrong date')
    quit()

print(f'(y){y}-(m){m}-(d){d}')
