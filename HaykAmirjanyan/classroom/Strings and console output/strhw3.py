#  Write a Python program to get a string from a given string where all occurrences 
# of its first char have been changed to '$', except the first char itself.
st = input("Enter the word: ")
c = st[0]
# st1 = ""
# for i in st:
#     if i == c:
#        st1 += '$'
#     else:
#         st1 += i 
# st = c + st1[1:]
# print(st)

st = st.replace(c,'$')
st = c + st[1:]
print(st)