# 2. Given three numbers a, b (a ≤ b) and step. 
# Create an array of evenly spaced elements starting from a to b spaced by step.

numbers = "1,5,1".split(',')

array = []

def create_array(n):
    for element in range(int(numbers[0]), int(numbers[1])+1, int(numbers[2])):
        array.append(element)
    return array    


print(create_array(numbers))