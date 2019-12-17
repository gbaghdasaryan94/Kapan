from sys import argv
import crypt

hash = argv[1]
a = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
aList = list(a)
key = ['A', 'A', 'A', 'A']
salt = '50'

for i in aList:
    key[0] = i
    for j in aList:
        key[1] = j
        for m in aList:
            key[2] = m
            for n in aList:
                key[3] = n
                kStr = ''.join(key)
                h = crypt.crypt(kStr, salt)
                if hash == h:
                    print(kStr)