def palindromeRearranging(inputString):
    abc = [0]*26
    t = 0
    for c in inputString:
          abc[ord(c) - 97] += 1
    for i in abc:
        if i % 2 == 1: t += 1
    return t<=1

print(palindromeRearranging(input("Enter String : ")))