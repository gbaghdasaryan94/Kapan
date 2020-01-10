# 4. Given an array of strings. Print the concatenation of all elements.


myarray = ["a",'c', 'a']


def concate_all_elements():
    # string = ''
    # for each_element in myarray:
    #     string += each_element
    return ''.join(myarray)

 
print(concate_all_elements())