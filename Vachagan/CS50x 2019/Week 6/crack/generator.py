from crypt import crypt
from sys import argv


if len(argv) != 2:
    exit(1)

hash = argv[1]

def check(word):
    print(word, " => ", crypt(word, hash[:2]))
    if crypt(word, hash[:2]) == hash:
        print(word)
        exit()


def generator_word(abc, wordLen, word = None):
    
    if wordLen == 0:
        check(''.join(word))
        return

    word = word or []
    
    for leter in abc:
        word.append(leter)
        generator_word(abc, wordLen-1, word)
        word.pop()


def run():

    abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
    for i in range(1,5):
        generator_word(abc, i)


if __name__ == "__main__":
    run()