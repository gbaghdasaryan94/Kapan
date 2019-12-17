a = float(input('a = '))
b = float(input('b = '))
s = float(input('s = '))
l = [a]

while a <= b - s:
    a += s
    l.append(a)

print(l)
