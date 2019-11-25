s = input('enter a string: ')

def mirror(s):
    if len(s) < 2: 
        return True
    if s[0] != s[-1]: 
        return False
    return mirror(s[1:-1])

print(mirror(s))
