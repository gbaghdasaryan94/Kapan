# 6. Given a sentence with missing words and an array of words. Replace all ‘_’ in a
# sentence with the words from the array.



def replace_underscores(sentence):
    # sentence = "May the _ _ _ _."
    replacewords = ["Force", 'be', 'with', 'you']
    count = 0
    for letter in sentence:
        if letter == "_": 
            sentence = sentence.replace("_", replacewords[count], 1)
            count += 1
    return sentence


print(replace_underscores('May the _ _ _ _.'))