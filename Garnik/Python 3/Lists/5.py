# 5. Given an array. Create the array which elements are products between two neighbours.


def multiplicated_items(new_input):
    # my_array = [1, 1, 4, 32, 6]
    final_array = []
    for element in range(len(new_input)):
        if element != len(new_input)-1:
            final_array.append(new_input[element] * new_input[element+1])
    return final_array


print(multiplicated_items([1, 1, 4, 5, 6]))
