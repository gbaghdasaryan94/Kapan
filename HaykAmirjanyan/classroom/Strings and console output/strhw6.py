# Write a Python program to remove the characters which have odd index values of a given string.
def f(st):
    arr = st.split(" ")
    return max(len(i) for i in arr)
st = input("Enter words array: ")
print(f(st))