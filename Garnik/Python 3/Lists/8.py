
def print_types(given_list):

    """8. Given an array of strings and numbers. 
    Print the number of integers and the number of strings in the array."""
    number, string = 0,0
    
    for items in given_list:
        if type(items) == int:
            number +=1
        elif type(items) == str:
            string +=1

    return f'Numbers: {number}, Strings: {string}'

print(print_types([1, 4, 'i am a string', '456']))            

