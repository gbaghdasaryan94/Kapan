# Given a string, compute recursively (no loops) a new string where all 
# appearances of "pi" have been replaced by "3.14".

def func(st,n):
    st1 = ""
    if n < len(st) - 1:
        if st[n:n + 2].lower() == "pi":
            st1 += "3.14" + func(st, n + 2)
            return st1
        else:
            st1 += st[n:n + 1] + func(st,n + 1)
            return st1
    else:
        st1 += st[n:]
        return st1

st = input("Enter word: ")
n = 0
print(func(st,n))