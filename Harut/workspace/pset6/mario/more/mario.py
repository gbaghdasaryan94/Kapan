n = 0
while True:
    n = input("height: ")
    if n.isdigit() and int(n) > 0 and int(n) < 9:
        break
n = int(n)

for i in range(1, n+1):
    print(' ' * (n-i) + '#' * i + '  ' + '#' * i)