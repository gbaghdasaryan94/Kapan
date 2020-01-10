
def copy_content():

    '''6. Write a Python program to copy the contents of a file to another file .'''

    with open('read.txt') as read_file:
        words = read_file.read()

    with open('copy_of_read.txt', 'a') as copy_file:
        copy_file.write(words)

    with open('copy_of_read.txt') as copy_file:
        return copy_file.read()        

print(copy_content())