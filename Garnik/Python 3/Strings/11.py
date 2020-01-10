# 11. Write a Python program to remove a newline in Python.

string = "this is 1st line\nthis is 2nd line\nthis is 3rd line".replace("\n", '')
print(string)

# below does not work why ?
# string = "this is 1st line\nthis is 2nd line\nthis is 3rd line\n\n\n"
# print(string.rstrip('\n'))
