# Given mixed array of numbers, strings, booleans and nulls.
# Filter array and get all the numbers in a separate array. 
# Arrange them such as from the beginning are the odds and from the ending the evens.

arr = [8, 0, 1, 'hey', 12, 5 , True, '2', None, 7, 3]
ar = []
ar1 = []
for i in arr:
    if type(i) == int or type(i) == float:
        if i % 2 == 1:
            ar.append(i)
        else:
            ar1.append(i)
for j in ar1:
    ar.append(j)
print(ar)