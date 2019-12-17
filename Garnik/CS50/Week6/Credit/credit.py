from cs50 import get_string, get_int

credit = (str(get_int("Please enter the CC number: ")))[::-1]

even = 0
for ev in credit[0::2]:
    even = even + int(ev)

odd = 0
for val in credit[1::2]:
    odd = odd + ((int(val) * 2)//10 + (int(val) * 2) % 10)

cc = odd + even
if cc % 10 == 0:
    if len(credit) in [13, 15, 16]:
        credit = int(credit)
        if credit % 10 == 4 or credit % 10 == 2:
            print("VISA")
        elif credit % 100 == 73 or credit % 100 == 43:
            print("AMEX")
        elif credit % 100 >= 15 or credit % 100 <= 55:
            print("MASTERCARD")
        else:
            print("INVALID")
        exit(0)

print("INVALID")
