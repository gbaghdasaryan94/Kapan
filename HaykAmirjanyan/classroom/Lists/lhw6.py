# Given a sentence with missing words and an array of words. Replace all ‘_’ in a 
# sentence with the words from the array.

st = "If at _ you don’t _, try, try _."
arr = ["first", "succeed", "again"]
st1 = ""
j = 0
for i in st:
    if i == "_":
        st1 += arr[j]
        j += 1
    else:
        st1 += i
print(st1)
