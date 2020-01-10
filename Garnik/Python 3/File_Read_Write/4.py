
def find_longest_word():
    '''Write a python program to find the longest words.'''

    mylist = []
    with open('read.txt') as longestword:
        for line_items in longestword:
            for word in line_items.split():
                mylist.append(word)
        return max(mylist, key=len)        


print(find_longest_word())