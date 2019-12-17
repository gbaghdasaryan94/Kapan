n = (input('enter binary numbers, separated by comma: ').split(','))
ns = []

for i in n:
    if int(i.strip(), 2) % 5 == 0:
        ns.append(i.strip())

print(','.join(ns))
