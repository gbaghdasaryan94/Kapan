# 14. Write a Python program to check if a string contains all letters of the alphabet.
import string

alphabet = set(string.ascii_lowercase)

text = "This is my string which should contain all alphabetical characters".lower()
print(set(text) >= alphabet)


        
