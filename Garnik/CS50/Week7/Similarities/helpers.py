from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""
    # ln1 = set(a.split("\n"))
    # ln2 = set(b.split("\n"))
    similar = []

    for i in set(a.split("\n")):
        if i in set(b.split("\n")):
            similar.append(i)
            # print(i)

    return similar


def sentences(a, b):
    """Return sentences in both a and b"""
    sent1 = set(sent_tokenize(a))
    sent2 = set(sent_tokenize(b))
    sentence = []

    for i in sent1:
        if i in sent2:
            sentence.append(i)
            # print(i)

    return sentence


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    sbstring1 = []
    sbstring2 = []

    for i in range(len(a)-n+1):
        sbstring1.append(a[i:i+n])

    for j in range(len(b)-n+1):
        sbstring2.append(b[j:n+j])

    sb3 = []

    for sb in sbstring1:
        if sb in sbstring2:
            sb3.append(sb)

    return set(sb3)
