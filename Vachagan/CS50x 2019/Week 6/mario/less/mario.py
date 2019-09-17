n = 0
while n < 1 or n > 8:
    n = input("Height: ")
    while not n.isnumeric():
        n = input("Height: ")
    n = int(n)

for i in range(n):
    print(" " * (n - i - 1), end="")
    print("#" * (i + 1))
