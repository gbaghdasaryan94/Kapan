import string


def letters():
    '''2. Make a dictionary of the 26 english alphabets mapping each with the corresponding integer'''
    
    return {letter: ord(letter)-96 for letter in string.ascii_lowercase}

print(letters())