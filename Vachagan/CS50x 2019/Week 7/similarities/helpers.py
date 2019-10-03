from nltk.tokenize import sent_tokenize
# import nltk
# nltk.download('punkt')

def lines(a, b):
    """Return lines in both a and b"""

    a = set(a.split('\n'))
    b = set(b.split('\n'))
    
    return a & b

    # a = a.split('\n')
    # b = b.split('\n')
    # m = min(len(a), len(b))
    # print([a[i] for i in range(m) if a[i] == b[i]])
    # return [a[i] for i in range(m) if a[i] == b[i]]


def sentences(a, b): 
    """Return sentences in both a and b"""
    a = set(sent_tokenize(a))
    b = set(sent_tokenize(b))
    return a & b


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    return []

# def substring_tokenize(str, n):
#     substrings = []

#     for i in range(len(str) - n + 1):
#         substrings.append(str[i:i + n])

#     return substrings


# def substrings(a, b, n):
#     """Return substrings of length n in both a and b"""

#     a_substrings = set(substring_tokenize(a, n))
#     b_substrings = set(substring_tokenize(b, n))

#     return a_substrings & b_substrings