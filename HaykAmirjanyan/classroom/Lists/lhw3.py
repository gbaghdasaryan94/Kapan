#  Given an array of numbers. Find the maximum element in array.Whitout use max function.

arr = [1,10,2,2,3,1,4,43,-112,0]
n = arr[1]
for i in arr[1:]:
    if i > n:
        n = i
print(n)