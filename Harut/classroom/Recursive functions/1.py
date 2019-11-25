n = int(input('enter a number: '))

def odd(n):
    if n > 0:
        if not n % 2:
            return False
        return odd(n // 10)
        
    return True

print(odd(n))
