from cs50 import get_string
from sys import argv


def main():

    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    user = get_string("Please enter words: ").split()

    # Read from a file
    r = open(argv[1], "r")
    words = r.read().split()
    for bar in range(len(user)):
        if user[bar].lower() in words:
            user[bar] = "*" * len(user[bar])

    print(' '.join(user))


if __name__ == "__main__":
    main()
