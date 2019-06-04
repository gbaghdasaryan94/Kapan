def arrayMaximalAdjacentDifference(inputArray):
    dif = 0
    for i in range(1,len(inputArray)):
        if dif < abs(inputArray[i-1]-inputArray[i]):
            dif = abs(inputArray[i-1]-inputArray[i])
    return dif

arr = [int(val) for val in input("Enter arr : ").split()]
print(arrayMaximalAdjacentDifference(arr))