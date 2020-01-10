

def negate(array):
    return (array[:3] + [-element for element in array[3:8]]+ array[8:])

print(negate([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])) 
