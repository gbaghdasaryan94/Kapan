string1 = input("Enter a string separated by space: ")
str1 = string1.split() # to get each item in the given string

output = str1[1][0:2] + str1[0][2:] + ' ' + str1[0][0:2] + str1[1][2:] 
print(output)
