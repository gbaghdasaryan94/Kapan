# Write a Python program to check a triangle is equilateral, isosceles or scalene.
x = int(input("Enter integer number: "))
y = int(input("Enter integer number: "))
z = int(input("Enter integer number: "))
if x == y and x == z:
    print("Equilateral triangle")
    quit()
elif x != y and x != z and y != z:
    print("Scalene triangle")
    quit()
else:
    print("Isosceles triangle")
