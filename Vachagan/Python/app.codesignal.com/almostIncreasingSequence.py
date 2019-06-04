def almostIncreasingSequence(sequence):
    isOne = False
    last = prev = min(sequence) - 1

    for elm in range(sequence):
        if elm <= last:
            if isOne:
                return False
            else:
                isOne = True

            if (elm <= prev):
                prev = last
            elif (elm >= prev):
                prev = last = elm
        else:
            prev, last = last, elm

    return True

print(almostIncreasingSequence([int(elm) for elm in input("Enter array: ").split()]))