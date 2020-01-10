# 1. Write a Python program to read an entire text file.


def read_file():
    file_read = open("read.txt", "r")
    return file_read.read()

print(read_file())