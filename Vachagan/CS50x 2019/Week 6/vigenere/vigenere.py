from sys import argv
from cs50 import get_string


def main(argv):

    if (len(argv) != 2):
        print("Please enter valid [KEY], ex. ./vigenere abc")
        exit(1)
    
    keyword = argv[1]
    for lt in keyword:
        if not lt.isalpha():
            print("Please enter valid [KEY], KEY only can alpha")
            exit(1)

    sentence = get_string("plaintext: ")

    key = 0
    keyLen = len(keyword)
    
    print("ciphertext: ", end='')
    for lt in sentence:
        if lt.isalpha():
            ltAscii = 65 if ord(lt) < 97 else 97
            lt = chr((ord(lt) - ltAscii + ord(keyword[key].lower()) - 97) % 26 + ltAscii)
            key += 1
        if (key == keyLen):
            key = 0
        print(lt, end='')
    print()
    exit(0)


if __name__ == "__main__":
    main(argv)