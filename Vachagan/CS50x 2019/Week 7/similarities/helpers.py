from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    a = set(a.split('\n'))
    b = set(b.split('\n'))
    return a & b


def sentences(a, b):
    """Return sentences in both a and b"""
    a = set(sent_tokenize(a))
    b = set(sent_tokenize(b))
    return a & b


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    a = set([a[i:i+n] for i in range(len(a) - n + 1)])
    b = set([b[i:i+n] for i in range(len(b) - n + 1)])
    return a & b