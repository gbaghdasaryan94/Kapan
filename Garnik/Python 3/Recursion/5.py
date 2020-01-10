# 5. Given a string. Return true, if it is mirror symmetric to its middle symbol.

string = input("Please enter a string: ")
mirror = 'AHIMOTUVWXY'.lower()

def if_mirror(s):
    if s[0] in mirror:
        if len(s) <= 2 and s[0] == s[-1]:
            return True
        else:
            if s[0] != s[-1]:
                return False
            else:
                return if_mirror(s[1:-1])
    else:
        return False            
        
print(if_mirror(string))            

