#  Write a Python program to check a string represent an integer or not.
n = input("Enter text: ")
n = n.strip()
if len(n) < 1:
    print("The text is invalid!!!")
    quit()
for i in n[1:]:
    if not i.isdigit() or ( not n[0].isdigit() and n[0] not in "+-"):
        print("The string is not an integer.")
        quit()
print("The string is an integer.")




