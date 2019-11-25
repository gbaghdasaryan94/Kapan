n = int(input('enter a number: '))


def num(n, i = 1):
    if i < n:
        print(i, end = ' ')
        return num(n, i + 1)
    return n
    

print(num(n))
