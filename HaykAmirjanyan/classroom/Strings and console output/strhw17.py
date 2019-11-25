# Check if given string can be derived from another string by circularly rotating it.
# The rotation can be in clockwise or anti-clockwise rotation.
st = input("Input string: ")
sst = input("Input substring: ")
for i in range(len(st)):
    if sst[0] == st[i]:
        a = i
        
if (st[a:] + st[0:a]) == sst:
    print("The rotation is in clockwise")
elif  (st[a::-1] + st[len(st) - 1:a:-1] == sst): #(st[a:0:-1] + st[0] + st[len(st) - 1:a:-1]) == sst:
    print("The rotation is anti-clockwise rotation.")
else:
    print("It does not have rotation!!!")