# Given a string. Return true, if it is mirror symmetric to its middle symbol.

def func(st,n):
    if n < len(st) // 2:
        if st[:n] == st[:-n - 1:-1]:
            return func(st,n + 1)
        else:
            return False
    else:
        return True

st = input("Enter word: ").lower()
n = 1
print(func(st,n))