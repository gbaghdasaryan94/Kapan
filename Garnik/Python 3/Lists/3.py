# 3. Given an array of numbers. Find the maximum element in array.Whitout use max function.


mylist = [1,3,4,6,-2,0,-9, 10]

maxvalue = mylist[0]
def get_max_value(n):
    global maxvalue
    for i in n:
        if i > maxvalue:
            maxvalue = i
    return maxvalue        


print(get_max_value(mylist))    