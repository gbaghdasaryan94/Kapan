from sys import argv
from cs50 import get_string


def main(argv):

    if (len(argv) != 2):
        print("Usage: ./caesar key\n")
        exit(1)

    key = int(argv[1]) % 26
    word = get_string("plaintext: ")
    print("ciphertext: ", end='')
    for leter in word:
        if (leter.isalpha()):
            asciiLeter = 65 if ord(leter) < 97 else 97
            leter = chr((ord(leter) + key - asciiLeter) % 26 + asciiLeter)
        print(leter, end='')
    print()
    exit(0)


if __name__ == "__main__":
    main(argv)
