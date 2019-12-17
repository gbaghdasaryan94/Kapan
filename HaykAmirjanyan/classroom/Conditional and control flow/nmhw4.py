# Write a Python program to count the number of even and odd numbers from a series of numbers.
a,b = 0,0
n = input("Enter only number please: ")
for i in n:
    if i.isnumeric():
        if int(i) % 2 == 0:
            a += 1
        else:
            b += 1
    # else:
    #     print("Number of even numbers :",a)
    #     print("Number of odd numbers :",b)
    #     print("Enter only number!!!")
    #     quit()
print("Number of even numbers :",a)
print("Number of odd numbers :",b)