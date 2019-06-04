def allLongestStrings(inputArray):
    max = len(inputArray[0])
    newStr = []
    for line in inputArray:
        if max < len(line):
            max = len(line)
            newStr.clear()
            newStr.append(line)
        elif max == len(line):
            newStr.append(line)

    return newStr
