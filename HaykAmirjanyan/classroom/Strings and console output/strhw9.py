# Write a Python program that accepts a 
# comma separated sequence of words as input and prints 
# the unique words in sorted form (alphanumerically).
st = input("Enter the string: ")
arr = st.split(',')
arr.sort()
arr = set(arr)
print(",".join(arr))