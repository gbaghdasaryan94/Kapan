l = input('enter words separated by space: ').split()


def longest(l):    
    max = l[0]

    for i in l:
        if len(i) > len(max):
            max = i
    
    return max
    

print(f'the longest word is: {longest(l)}')
