# 3. Write a Python program to read a file line by line and store it into a list.

def read_by_line():
    mylist = []
    with open('read.txt', 'r') as readbyline:
        mylist.append(readbyline.readlines())
    return mylist

print(read_by_line())