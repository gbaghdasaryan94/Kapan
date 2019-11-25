# Write a Python program to calculate a dog's age in dog's years.
age = int(input("Input a dog's age in human years: "))
if age < 0:
    print("Input positive number")
elif age > 2:
    a = 21 + (age - 2) * 4
else:
    a = age * 10.5
print("Input a dog's age in human years: ",age)
print("The dog's age in dog's years is",a)