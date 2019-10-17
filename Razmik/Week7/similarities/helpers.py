from nltk.tokenize import sent_tokenize


def lines(a, b):
    aa = a.split('\n')
    bb = b.split('\n')
    return set(c for c in aa if c in bb)


def sentences(a, b):
    aa = set(sent_tokenize(a))
    bb = set(sent_tokenize(b))
    return [c for c in aa if c in bb]


def substrings(a, b, n):
    alen = len(a)
    blen = len(b)
    aa = set(a[i:i+n] for i in range(alen-n+1))
    bb = set(b[i:i+n] for i in range(blen-n+1))
    return [c for c in aa if c in bb]
