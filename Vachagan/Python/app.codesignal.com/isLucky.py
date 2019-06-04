def isLucky(n):
    arr = [int(d) for d in str(n)]
    ln = len(arr)/2
    return sum(arr[:ln])==sum(arr[ln:])