n = int(input('enter a number: '))


def sum(n):
    if n > 9:
        return sum(n % 10 + sum(n // 10))
    else:
        return n
    

print(sum(n))
