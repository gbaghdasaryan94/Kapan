# 10. Write a Python function to create the HTML string with tags around the word(s).

def add_tags(tag, text):
    print("<"+ tag + ">" + text + "</" + tag + ">")

add_tags("b", "New HTML title") 
