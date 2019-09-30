from sys import argv

def main():

    if len(argv) != 2:
        exit("Usage: python bleep.py dictionary")
    
    text = input("What message would you like to censor?\n").split()
    file = open(argv[1], "r")
    dictionary = file.read().split()
    file.close()
    
    text = ['*' * len(word) if word.lower() in dictionary else word for word in text]
    print(' '.join(text))
    

    # for i in range(len(text)):
    #     if text[i].lower() in dictionary:
    #         text[i] = '*' * len(text[i])
    


if __name__ == "__main__":
    main()
