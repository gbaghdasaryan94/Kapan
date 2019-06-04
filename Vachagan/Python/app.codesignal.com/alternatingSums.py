def alternatingSums(a):
    return [sum(a[::2]),sum(a[1::2])]

print(alternatingSums([int(v) for v in input("Enter array : ").split()]))