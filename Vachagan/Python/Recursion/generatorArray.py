def generateArray(abc, m, word):
    if m==0:
        print(word)
        return
    
    for leter in abc:
        newWord = [leter] + word
        generateArray(abc, m-1, newWord)

def main():

    abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    lenA = len(abc)

    for i in range(1, lenA + 1):
        generateArray(abc, i, [])

if __name__ == "__main__":
    main()