from cs50 import get_string
from sys import argv


def main():

    if len(argv) != 2:
        exit('usage: python bleep.py banned.txt')

    b = open(argv[1], 'r').read().split('\n')
    t = get_string("text: ").split(' ')
    tl = ' '.join(t).lower().split(' ')

    print(tl)


if __name__ == "__main__":
    main()
