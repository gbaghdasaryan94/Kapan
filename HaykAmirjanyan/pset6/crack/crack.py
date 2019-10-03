from crypt import crypt
from sys import argv

if len(argv) == 2:
    crypt_key = argv[1]
else:
    print("enter the key:")
    exit(1)

def check(word):
    if crypt(word, crypt_key[:2]) == crypt_key:
        print(word)
        exit()


def generator_word(alpha, wordlen, word=None):
    if wordlen == 0:
        check(''.join(word))
        return

    word = word or []

    for j in alpha:
        word.append(j)
        generator_word(alpha, wordlen - 1, word)
        word.pop()


def run():
    alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for i in range(1, 15):
        generator_word(alpha, i)


if __name__ == "__main__":
    run()
