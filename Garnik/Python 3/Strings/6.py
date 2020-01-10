# 6. Write a Python function that takes a list of words and returns the length of the longest one.
words_list = ['Test', 'Tester', 'testing']

def maxlength(words):
    print("The max len of an item is: ", len(max(words)))
    
maxlength(words_list)