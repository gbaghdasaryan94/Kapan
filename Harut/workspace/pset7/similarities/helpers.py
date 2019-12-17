from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    a = a.split('\n')
    b = b.split('\n')
    c = []

    for i in a:
        if i in b:
            c.append(i)
    return c


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    at = set(sent_tokenize(a))
    bt = set(sent_tokenize(b))
    c = []

    for i in at:
        if i in b:
            c.append(i)
    return c


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    la = len(a)
    lb = len(b)
    sub_a = []
    sub_b = []
    sub = []

    for i in range(la-n+1):
        sub_a.append(a[i:i+n])

    for j in range(lb-n+1):
        sub_b.append(b[j:j+n])

    for k in sub_a:
        if k in sub_b:
            sub.append(k)

    sub = set(sub)

    return sub