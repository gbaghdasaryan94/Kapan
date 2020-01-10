# 7. Write a Python program to remove the characters which have odd index values of a given string.

string = input("Please enter a string: ")
result = []
for i in range(0, len(string), 2):
    result.append(string[i])
print(''.join(result))



