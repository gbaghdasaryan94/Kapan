from sys import argv
from crypt import crypt

if len(argv) != 2:
    print("Error!")
    exit(1)
crack=[]
hash = argv[1]
abc = ' abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
len = len(abc)


salt = hash[0:2]

for j1 in range(len):
    for j2 in range(len):
        for j3 in range(len):
            for j4 in range(1, len):  
               ''' crack = abc[j4] + abc[j3] 
                crack = crack.strip() + abc[j2] 
                crack = crack.strip() + abc[j1]
                crack = crack.strip() '''
                crack.append(abc[j4]) 
                crack = str(crack)
                crack.replace(' ', '')
                if crypt(str(crack), salt) == hash:
                    print(crack)
                    break
