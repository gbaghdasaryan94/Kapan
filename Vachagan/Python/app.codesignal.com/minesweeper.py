def minesweeper(matrix):
    lnX = len(matrix)
    lnY = len(matrix[0])
    mines = [[0 for j in range(lnY)] for i in range(lnX)]

    for i in range(lnX):
        for j in range(lnY):
            for a in range(i - 1, i + 2):
                for b in range(j - 1, j + 2):
                    try:
                        if a < 0 or b < 0: # or a == i and b == j:
                            continue
                        if matrix[a][b]:
                            mines[i][j] += 1
                    except:
                        continue
            if matrix[i][j]:
                mines[i][j] -= 1
            # if i - 1 >= 0 and j - 1 >= 0 and matrix[i - 1][j - 1]:
            #     mines[i][j] += 1
            # if i-1 >= 0 and j+1 < lnY and matrix[i-1][j+1]:
            #     mines[i][j] += 1
            # if j-1 >= 0 and matrix[i][j-1]:
            #     mines[i][j] += 1
            # if i-1 >= 0 and matrix[i-1][j]:
            #     mines[i][j] += 1
            # if i+1 < lnX and j-1 >= 0 and matrix[i+1][j-1]:
            #     mines[i][j] += 1
            # if i+1 < lnX and j+1 < lnY and matrix[i+1][j+1]:
            #     mines[i][j] += 1
            # if j+1 < lnY and matrix[i][j+1]:
            #     mines[i][j] += 1
            # if i+1 < lnX and matrix[i+1][j]:
            #     mines[i][j] += 1
    return mines

# arr = [[v for v in input("Enter arr {0} : ".format(i)).split()] for i in range(int(input("Enter nxn : ")))]
arr = [[True, False, False],
       [False, True, False],
       [False, False, False]]
print(minesweeper(arr))