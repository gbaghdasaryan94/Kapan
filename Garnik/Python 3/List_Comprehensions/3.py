import string
    '''3. Replace all alphabets in the string ‘My name is {your name}’, 
    by substituting the alphabet with the corresponding numbers, 
    like 1 for ‘a’, 2 for ‘b’ and so on.'''
    
def replace_letters(text):
    return [ord(letter)-96 if letter in string.ascii_letters else letter for letter in text.lower()]

print(replace_letters(input("Please enter your name: ")))
