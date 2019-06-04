def adjacentElementsProduct(inputArray):
    maxP = min(inputArray)
    for elm in range(len(inputArray)-1):
        product = inputArray[elm] * inputArray[elm + 1]
        if product > maxP:
            maxP = product
    return maxP


print(adjacentElementsProduct([int(elm) for elm in input("Enter array: ").split()]))