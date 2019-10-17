def checkSum(card):
    return not sum(int(v) for v in ''.join([str(int(v) * 2) if i % 2 else v for i, v in enumerate(card)])) % 10
    # return not sum([int(v) for v in ''.join([str(int(v)*2) for v in card[1::2] if int(v)])] + [int(v) for v in card[0::2]]) % 10

def main():
    card = ''
    while not card.isdigit():
        card = input("Number: ")
    Message = "INVALID"
    if len(card) in [13, 15, 16] and checkSum(card[::-1]):
        if (card[0] == '3' and (card[1] == '4' or card[1] == '7')):
            Message = "AMEX"
        elif (card[0] == '5' and (card[1] > '0' and card[1] < '6')):
            Message = "MASTERCARD"
        elif (card[0] == '4'):
            Message = "VISA"
    print(Message)


if __name__ == "__main__":
    main()


# print(checkSum("378282246310005"[::-1]))
# print(checkSum("371449635398431"[::-1]))
# print(checkSum("5555555555554444"[::-1]))
# print(checkSum("5105105105105100"[::-1]))
# print(checkSum("4111111111111111"[::-1]))
# print(checkSum("4012888888881881"[::-1]))
# print(checkSum("1234567890"[::-1]))
# print(checkSum("4003600000000014"[::-1]))
# for card in ["378282246310005", "371449635398431", "5555555555554444", "5105105105105100", "4111111111111111", "4012888888881881", "4003600000000014", "1234567890"]:
#     main(card)
