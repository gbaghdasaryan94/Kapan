# Write a Python program to convert temperatures to and from celsius, fahrenheit.
num = input("Enter temperature: ") 
if num[-1:].upper() == "F":
    print(("%i" + "°F is " + "%i" + " in Celsius") % (int(num[:-1]),round((int(num[:-1]) - 32) * 5 / 9)))
elif num[-1:].upper() == "C":
    print(("%i" + "°C is " + "%i" + " in Fahrenheit") % (int(num[:-1]),round((9 * int(num[:-1]) / 5 + 32)))) 
else:
    print("Enter valid temperature")