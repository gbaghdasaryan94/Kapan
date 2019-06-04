def boxBlur(image):
    lnw = len(image)-2
    lnh = len(image[0])-2
    sumIMG = [[0 for i in range(lnh)] for j in range(lnw)]
    for i in range(lnw):
        for j in range(lnh):
            sumIMG[i][j] = sum([sum(line[j:j+3]) for line in image[i:i+3]])
            sumIMG[i][j] //= 9
    return sumIMG

# arr = [[int(v) for v in input("Enter arr {0} : ".format(i)).split()] for i in range(int(input("Enter nxn : ")))]
arr = [[7, 4, 0, 1],
       [5, 6, 2, 2],
       [6, 10, 7, 8],
       [1, 4, 2, 0]]
# arr = [[1, 1, 1], [1, 7, 1], [1, 1, 1]]
print(boxBlur(arr))