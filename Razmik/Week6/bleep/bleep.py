from sys import argv


def main():
    if len(argv) != 2:
        exit("Usage: python bleep.py dictionary")
    banned = open(argv[1], 'r').read().split('\n')
    sent = input("What message would you like to censor?\n")
    b = list("")
    for foo in sent.split(" "):
        b.append(foo if foo.lower() not in banned else ("*" * len(foo)))
    print(' '.join(b))


if __name__ == "__main__":
    main()
