# Given three numbers a, b (a ≤ b) and step. 
# Create an array of evenly spaced elements starting from a to b spaced by step.

arr = [4,5,-0.5]
arr1 = []
n = arr[0]
m = arr[2]
if arr[0] > arr[1]:
    print("Invalid array!!!")
    quit()
else:
    while n <= arr[1]:
        arr1.append(n)
        n += abs(m)
print(arr1)