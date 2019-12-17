# Write a Python function to create the HTML string with tags around the word(s).
def function(tag,word):
    return "<" + tag + ">" + word + "</" + tag + ">"
    # return <%s>%s</%s> % (tag,word,tag)

tag = input("Enter HTML tag: ")
word = input("Enter word: ")
print(function(tag,word))