# Write a Python program to convert month name to a number of days.
month = input("Enter month: ")
if month in ("April", "June", "September", "November"):
    print("No. of days: 30 days")
elif month in ("January", "March", "May", "July", "August", "October", "December"):
    print("No. of days: 31 day")
elif month == "February":
    print("No. of days: 28/29 days")
else:
    print("There is no such month")