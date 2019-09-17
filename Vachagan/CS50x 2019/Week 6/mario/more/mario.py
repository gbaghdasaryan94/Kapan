n = 0
while n < 1 or n > 8:
    n = input("Height: ")
    while not n.isnumeric():
        n = input("Height: ")
    n = int(n)


for i in range(1, n+1):
    print(" " * (n - i) + "#" * (i) + "  " + "#" * (i))
