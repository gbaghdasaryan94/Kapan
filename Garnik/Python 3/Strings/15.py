# 15. Write a Python program to remove duplicate characters of a given string.

string = "aaaabbbcjllclkasdyuuoyy"
text = ""
for i in string:
    if i not in text:
        text = text + i
print(text)