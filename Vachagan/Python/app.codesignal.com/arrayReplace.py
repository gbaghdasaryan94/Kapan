def arrayReplace(inputArray, elemToReplace, substitutionElem):
    return [substitutionElem if elemToReplace==val else val  for val in inputArray]

inputArray = [int(val) for val in input("Enter arr : ").split()]
elemToReplace = int(input("Enter elemToReplace : "))
substitutionElem = int(input("Enter substitutionElem : "))

print(arrayReplace(inputArray, elemToReplace, substitutionElem))