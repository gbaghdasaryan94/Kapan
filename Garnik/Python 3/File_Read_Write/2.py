# 2. Write a Python program to append text to a file and display the text.


def append_text_to_a_file():
    with open("read.txt", "a") as append_text:
        append_text.write("some text")
    with open("read.txt", "r") as read_text:
        return read_text.read()

print(append_text_to_a_file())