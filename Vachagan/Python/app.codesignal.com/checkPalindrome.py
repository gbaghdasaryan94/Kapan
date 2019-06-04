def checkPalindrome(inputString):
    inputString = inputString.lower()
    if len(inputString)%2 == 0:
        return inputString[:len(inputString)//2] == inputString[len(inputString)//2:][::-1]
    return inputString[:len(inputString)//2] == inputString[len(inputString)//2+1:][::-1]

print(checkPalindrome(input("Enter text: ")))