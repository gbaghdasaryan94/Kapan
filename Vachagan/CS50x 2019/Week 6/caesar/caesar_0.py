from sys import argv
from cs50 import get_string


def main(argv):

    if (len(argv) != 2):
        exit("Usage: ./caesar key")

    key = int(argv[1]) % 26
    word = get_string("plaintext: ")

    word = ''.join([chr((ord(lt) % 32 + key) % 26 + ord(lt) -
                        ord(lt) % 32) if lt.isalpha() else lt for lt in word])
    print("ciphertext:", word)


if __name__ == "__main__":
    main(argv)
