# Print the following number pattern:
# 1
# 2 6
# 3 7 10
# 4 8 11 13
# 5 9 12 14 15
n = 5
m = 0
arr = [[str(j) for i in range(j)]  for j in range(1,n + 1)]
print("\n".join([' '.join(i) for i in arr]))

