# Write a Python program to get next day of a given date.
year = int(input("Input a year: "))
month = int(input("Input a month [1-12]: "))
day = int(input("Input a day [1-31]: "))

if year % 400 == 0:
    a = True
elif year % 100 == 0:
    a = False
elif year % 4 == 0:
    a = True
else:
    a = False

if month in (4, 6, 9, 11):
    b = 30
elif month == 2:
    if a:
        b = 29
    else:
        b = 28
else:
    b = 31

if day < b:
    day += 1
else:
    day = 1
    if month == 12:
        month = 1
        year += 1
    else:
        month += 1

print("The next date is [yyyy-mm-dd] %d-%d-%d." % (year, month, day))