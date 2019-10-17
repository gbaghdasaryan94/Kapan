from cs50 import get_int


def check_sum(card):
    Sum = 0
    isTwo = False

    while card > 0:
        num = card % 10
        if isTwo:
            num *= 2
        isTwo = not isTwo

        Sum += num / 10 + num % 10
        card /= 10

    return Sum % 10


def main():
    card = get_int("Number: ")

    check = check_sum(card)
    st = str(card)
    Len = len(st)
    Message = "INVALID"

    if (Len == 15 and check and st[0] == '3' and (st[1] == '4' or st[1] == '7')):
        Message = "AMEX"
    if (Len == 16 and check and st[0] == '5' and (st[1] > '0' and st[1] < '6')):
        Message = "MASTERCARD"
    if ((Len == 13 or Len == 16) and check and st[0] == '4'):
        Message = "VISA"

    print(Message)


if __name__ == "__main__":
    main()
