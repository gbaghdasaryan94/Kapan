def list_of_words(sentences):
    '''5. Create a list of (word:id) pairs for all words in the following sentences, 
    where id is the sentence index.'''



    newlist =  [[bar for bar in barer.split(' ')] for barer in sentences]
    return [(item, newlist.index(line)) for line in newlist for item in line]

print(list_of_words(["The Hubble Space telescope has spotted",
"a formation of galaxies that resembles",
"a smiling face in the sky",]))        