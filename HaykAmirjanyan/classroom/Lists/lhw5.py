#  Given an array. Create the array which elements are products between two neighbours.

arr = [3, 7, 12, 5, 20, 0] #[1, 1, 4, 32, 6]
arr1 = []
for i in range(len(arr) - 1):
    arr1.append(arr[i] * arr[i + 1])
print(arr1)