

def write_content_to_file(mylist):
    
    """5. Write a Python program to write a list content to a file."""
    
    with open('read.txt', 'w') as add_to_the_file:
        for words in mylist:
            add_to_the_file.writelines(words)

    with open('read.txt', 'r') as read_file_after_writing:
        return read_file_after_writing.read()

print(write_content_to_file(['a', 'b', 'y strimng'])) 