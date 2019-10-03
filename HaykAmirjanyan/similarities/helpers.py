from nltk.tokenize import sent_tokenize
import nltk
nltk.download('punkt')


def lines(a, b):
    # """Return lines in both a and b"""

    a_file = a.split('\n')
    b_file = b.split('\n')
    c = []
    for item in a_file:
        if item in b_file:
            c.append(item)
    return c


def sentences(a, b):

    # """Return sentences in both a and b"""
    afile = sent_tokenize(a)
    bfile = sent_tokenize(b)

    c = []
    for item in afile:
        if item in bfile:
            c.append(item)

    c = set(c)
    return c


def substrings(a, b, n):
    # """Return substrings of length n in both a and b"""
    arr_a = []
    arr_b = []
    n = int(n)
    for i in range(len(a) - n + 1):
        aa = a[i:i + n]
        arr_a.append(aa)
    for j in range(len(b) - n + 1):
        bb = b[j:j + n]
        arr_b.append(bb)
    c = []
    for item in arr_a:
        if item in arr_b:
            c.append(item)
    c = set(c)
    return c