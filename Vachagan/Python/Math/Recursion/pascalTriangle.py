cache = [0, 1]
def fact(n):
    if n < 2: return 1 
    if len(cache) == n:
        cache.append(n * fact(n-1))
    return cache[n]


def pascal(n):
    
    triangle = []

    for i in range(n):
        

for i in range(10000):
    print(fact(i))

