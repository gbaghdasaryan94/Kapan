def evenDigitsOnly(n):
    return all(not int(num)%2 for num in str(n))
    # return all(not int(num)%2 for num in [int(x) for x in str(n)])

print(evenDigitsOnly(input("Enter Number : ")))