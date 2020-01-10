# 17. Check if given string can be derived from another string by circularly rotating it.
#  The rotation can be in clockwise or anti-clockwise rotation.


string1 = "abc"
string2 = "cab"
check = False
for i in range(0, len(string2)):
    if string1 == (string2[i::] + string2[0:i]):
        check = True
        break
print("Found") if check else print("Not Found")
    


