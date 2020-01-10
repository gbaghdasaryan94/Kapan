# 6. Given a string, compute recursively (no loops) a new string 
# where all appearances of "pi" have been replaced by "3.14".

text = input("Please enter an a text: ")
pi = 'pi'
new_string = ''

def replace_pi_with_3_14(s):
    if s == pi:
        return s.replace(s, "3.14")
    else:
        print(s.index('pi'))


replace_pi_with_3_14(text)


