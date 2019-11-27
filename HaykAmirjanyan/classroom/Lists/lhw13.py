# Print the following number pattern:
# 1
# 2 6
# 3 7 10
# 4 8 11 13
# 5 9 12 14 15

n = 6
arr = []
for i in range(n):
    arr.append([])
    for j in range(n):
        if j == 0:
            arr[i].append(str(i + 1))
        elif j <= i:
            arr[i].append(str(int(arr[i][j - 1]) + n - j))
print("\n".join([' '.join(i) for i in arr]))