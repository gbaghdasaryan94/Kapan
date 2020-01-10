string = input("Enter a string: ")
if len(string) < 2:
    print ("Empty String")
else:
    word = string[0]+ string[1] + string[-2] + string[-1]
    print(word)


