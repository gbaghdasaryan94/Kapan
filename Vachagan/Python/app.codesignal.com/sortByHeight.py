def sortByHeight(a):
    sortA = sorted([v for v in a if v > 0])
    for k,v in enumerate(a):
        if v == -1:
            sortA.insert(k,v)
    return sortA