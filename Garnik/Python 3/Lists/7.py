
def get_ints(mixed_array):
    filtered_list = []
    """Given mixed array of numbers, strings, booleans and nulls.
    Filter array and get all the int numbers in a separate array.
    Arrange them such as from the beginning are the odds and from the ending the evens."""
    
    for items in mixed_array:
        if type(items) == int:
            filtered_list.append(items)
                
    odd = list(filter(lambda odd:odd % 2, filtered_list))
    even = list(filter(lambda even:even %2 == 0, filtered_list))
    
    return odd + even

print(get_ints([8, 0, 1, 'hey', 12, 5 , True, '2', None, 7, 3]))