def areSimilar(a, b):
    count = [i for i in range(len(a)) if a[i] != b[i]]
    print(count)
    return len(count) == 0 or len(count) == 2 and a[count[0]] == b[count[1]] and b[count[0]] == a[count[1]]

a = [int(v) for v in input("Enter array a : ").split()]
b = [int(v) for v in input("Enter array b : ").split()]

print(areSimilar(a,b))
