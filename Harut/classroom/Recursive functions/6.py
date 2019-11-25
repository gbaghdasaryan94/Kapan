s = input('enter a string: ')


def pi(s): 
    if len(s) > 1:
        if s in ('pi', 'pI' 'Pi', 'PI'):
            return '3.14'
        elif s[:2] in ('pi', 'pI', 'Pi', 'PI'):
            return '3.14' + pi(s[2:])
        else:
            return s[0] + pi(s[1:])  
    return s

    
print(pi(s))
