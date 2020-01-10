# 2. Write a Python program to convert temperatures to and from celsius, fahrenheit.

temp = input("Enter temperature: ")

if temp[-1] == 'C' and temp[:-1].isdigit():
    print("The temperature in farenheit is", (int(temp[:-1]) * 9/5 + 32))
elif temp[-1] == 'F' and temp[:-1].isdigit():
    print("The temperature in celsius is", (float(temp[:-1]) * 5/9))
else:
    print("Please use valid imput format: Should be number + C/F (20C or 68F)")        
