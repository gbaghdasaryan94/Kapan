from cs50 import get_string
from sys import argv


def main():

    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    
    text = input("What message would you like to censor?")

    file = open(argv[1], "r")
    
    dictionary = file.readlines()

    print(text, dictionary)

    # TODO


if __name__ == "__main__":
    main()
