from crypt import crypt
from sys import argv
from cs50 import get_string


def generate(arr, i, s, len, hash):

    if (i == 0):
        print(s, crypt(s, hash[:2]))
        if (hash == crypt(s, hash[:2])):
            print(s)
            exit()
        return

    for j in range(0, len):
        appended = arr[j] + s
        generate(arr, i - 1, appended, len, hash)

    return


def main():

    if (len(argv) != 2):
        print("Usage: python crack.py hash")
        exit(1)
    
    arr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    lenA = len(arr)
    hash = argv[1]

    for i in range(1, lenA + 1):
        generate(arr, i, "", lenA, hash)


# arr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# len = len(arr)
# hash = crypt.crypt("vachagan", "50")#"50JGnXUgaafgc"
# crack(arr, len, hash)

if __name__ == "__main__":
    main()
