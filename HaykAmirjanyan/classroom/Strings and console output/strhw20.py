# Given a string, find all possible palindromic substrings in it.
st = input("Enter string: ")
arr = []
for j in range(len(st)):
    n = 0
    while j + n <= len(st):
        a = st[j:j + n]
        b = a[::-1]
        if a == b:
            arr.append(a)
        n += 1
arr = sorted(set(arr))
for k in arr[1:]:
    print(k)

