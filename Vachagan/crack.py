import crypt, sys

def generate(arr, i, s, len, hash):

    if (i == 0):
        print(s, crypt.crypt(s, "50"))
        if (hash == crypt.crypt(s, "50")):
            print("Key /", s, "/", crypt.crypt(s, "50"))
            sys.exit()
        return

    for j in range(0, len):
        appended = arr[j] + s
        generate(arr, i - 1, appended, len, hash)

    return


def main():
    arr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    lenA = len(arr)
    hash = crypt.crypt("vachagan", "50")#"50JGnXUgaafgc"

    for i in range(1, lenA + 1):
        generate(arr, i, "", lenA, hash)


# arr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# len = len(arr)
# hash = crypt.crypt("vachagan", "50")#"50JGnXUgaafgc"
# crack(arr, len, hash)

# if __name__ == "__main__":
#     main()

print(crypt.crypt("vachagan", "50"))