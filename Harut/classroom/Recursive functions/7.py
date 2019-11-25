n = int(input('enter a number: '))

def rev(n, s = 0):
    s = s * 10 + n % 10
    if n // 10 != 0:
        return rev (n // 10, s)
    return s

print(rev(n))
