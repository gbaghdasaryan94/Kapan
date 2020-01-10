string = input("Enter a string: ")

if len(string) > 2:
    if string.endswith("ing"):
        print(string + "ly")
    else: 
        print(string + "ing")
else:
    print(string)