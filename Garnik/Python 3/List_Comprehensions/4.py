def list_of_words(sentences):
    '''4. Get the list of words from the following sentences, 
    excluding all stopwords and punctuations.'''


    stopwords = ['the','for', 'a', 'of', 'the', 'and', 'to', 'in', 'on', 'with']

    return [[bar for bar in barer.split(' ') if bar not in stopwords] for barer in sentences]
    
print(list_of_words(["The Hubble Space telescope has spotted",
"a formation of galaxies that resembles",
"a smiling face in the sky",
"The image taken with the Wide Field Camera",
"shows a patch of space filled with galaxies",
"of all shapes, colours and sizes"]))
