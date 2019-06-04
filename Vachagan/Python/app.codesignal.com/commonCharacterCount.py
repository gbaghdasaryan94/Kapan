def commonCharacterCount(s1, s2):
    com = [min(s1.count(i),s2.count(i)) for i in set(s1)]
    return sum(com)

print(commonCharacterCount(input("Enter s1: "),input("Enter s2: ")))