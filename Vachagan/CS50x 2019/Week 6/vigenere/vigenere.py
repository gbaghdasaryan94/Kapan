from sys import argv
from cs50 import get_string
from itertools import cycle


def main(argv):

    if (len(argv) != 2):
        exit("Please enter valid [KEY], ex. ./vigenere abc")

    if not argv[1].isalpha():
        exit("Please enter valid [KEY], KEY only can alpha")

    sentence = get_string("plaintext: ")
    keyOrd = cycle([ord(lt) - 97 for lt in argv[1].lower()])
    sentence = ''.join([chr((ord(lt) % 32 + next(keyOrd)) % 26 + ord(lt) -
                            ord(lt) % 32) if lt.isalpha() else lt for lt in sentence])
    print("ciphertext:", sentence)

    # print("ciphertext: ", end='')
    # for lt in sentence:
    #     if lt.isalpha():
    #         case = ord(lt)%32
    #         lt = chr((case + next(keyOrd)) % 26 +   ord(lt) - case)
    #     print(lt, end='')
    # print()


if __name__ == "__main__":
    main(argv)
