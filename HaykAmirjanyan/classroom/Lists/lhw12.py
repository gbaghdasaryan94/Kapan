# Print the following pattern:
# * * * * *
# *       *
# *       *
# *       *
# * * * * *

n = int(input("Enter number: "))
arr = [["*"   if i == 0 or i == n - 1 or j == 0 or j == n - 1 else " " for i in range(n)]  for j in range(n)]
print("\n".join([' '.join(i) for i in arr]))
