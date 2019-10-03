from cs50 import get_int

card_number = get_int("Number your card: ")
number = [int(x) for x in str(card_number)]
number.reverse()
sum = 0
for i in range(0, len(number), 2):
    sum = sum + number[i]
for j in range(1, len(number), 2):
    sum += (number[j] * 2) //10 + (number[j] * 2) % 10
number.reverse()
if (number[0] == 4 and sum % 10 == 0 and (len(number) == 13 or len(number) == 16)):
    print("VISA")
elif (len(number) == 16 and number[0] == 5 and number[1] < 6 and sum % 10 == 0):
    print("MASTERCARD")
elif (len(number) == 15 and number[0] == 3 and (number[1] == 4 or number[1] == 7) and sum % 10 == 0):
    print("AMEX")
else:
    print("INVALID")