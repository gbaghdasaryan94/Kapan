# 8. Given N number. Write a recursive function that should print from 1 to N numbers.

num =  abs(int(input("Please neter a number: ")))


def print_up_to_num(n):
    if n > 0:
        print_up_to_num(n - 1)
        print(n, end=',')


print_up_to_num(num)  