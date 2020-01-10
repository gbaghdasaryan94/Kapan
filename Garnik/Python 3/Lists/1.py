# 1. Write a Python program to sum all the items in a list. Without use sum function.


mylist = [1,2,4,5,67,0,-70,-2]

def summ_all_elements(x):
    summ = 0
    for element in x:
        summ += element
    return summ    


print(summ_all_elements(mylist))