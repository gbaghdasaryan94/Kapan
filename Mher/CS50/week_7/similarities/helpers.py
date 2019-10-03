from nltk import sent_tokenize
import nltk
nltk.download('punkt')

def lines(a, b):
    """Return lines in both a and b"""

    a.split('/n')
    b.split('/n')
    
    c = []
    for i in a:
        for j in b:
            if i == j:
                c = set(j)

    return c


def sentences(a, b):
    """Return sentences in both a and b"""

    a = sent_tokenize(a)
    b = sent_tokenize(b)
    c = []
    for i in a:
        for j in b:
            if i == j:
                c = set(j)

    return c


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    
    return []
