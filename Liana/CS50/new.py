from cs50 import get_int


while True:
    cc = get_int("card number = ")
    if cc >= 0:
        break
print(cc)
i2 = 0
i1 = 0
k2 = 0
digit_num = 1
while cc > 0:

    i1 = i1 + cc % (10)
    digit = cc % (10)
    if digit_num == 13:

        digit_13 = digit

    if digit_num == 15:

        digit_15 = digit

    cc = ((cc - cc % (10)) // 10)
    if cc > 0:

        digit_num = digit_num + 1

    k2 = (2 * (cc % (10)))
    if k2 > 9:

        k2 = ((k2 % 10) + (k2 // 10))

    i2 = i2 + k2
    digit = cc % (10)
    if digit_num == 14:

        digit_14 = digit

    if digit_num == 16:

        digit_16 = digit

    cc = ((cc - cc % (10)) // 10)
    if cc > 0:

        digit_num = digit_num + 1

sum = i2 + i1
if sum % 10 == 0 and digit_num == 15 and digit_15 == 3 and (digit_14 == 4 or digit_14 == 7):

        print("AMEX")

elif sum % 10 == 0 and digit_num == 16 and digit_16 == 5 and (digit_15 == 1 or digit_15 == 2 or digit_15 == 3
        or digit_15 == 4 or digit_15 == 5):

        print("MASTERCARD")

elif sum % 10 == 0 and digit_num == 13 and digit_13 == 4:

        print("VISA")

elif sum % 10 == 0 and digit_num == 16 and digit_16 == 4:

    print("VISA")

else:
    print("INVALID")




