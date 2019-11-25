# Check if given string is a rotated palindrome or not.

# inputString = input("Enter word:" )
# st = "".join([i for i in set(inputString)])
# m = 0
# for i in st:
#     s = sum([inputString.count(i)])
#     if s % 2 != 0:
#         m += 1
# print(m <= 1)

st = input("Enter word:" )
if st == st[::-1]:
    print(True)
    quit()
else:
    for i in range(1,len(st)):
        st1 = st[-i:] + st[:-i]
        if st1 == st1[::-1]:
            print(True)
            quit()
print(False)