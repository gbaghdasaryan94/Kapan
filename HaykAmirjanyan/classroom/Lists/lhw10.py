# Given an array of numbers and a number. 
# Find the index of a first element which is equal to that number. 
# If there is not such a number, that find the index of the first element which is the closest to it.

arr  = [21, -9, 15, 2116, -71, 33]
n = -71
m = [n - arr[0] if n > arr[0] else arr[0] - n]
index = 0
for i in range(1,len(arr)):
    if arr[i] >= n:
        if (arr[i] - n) < m[0]:
            m[0] = arr[i] - n
            index = i
    elif (n - arr[i]) < m[0]:
        m[0] = n - arr[i]
        index = i
print(index)