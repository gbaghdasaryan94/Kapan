def chess_board():
    '''6. Print the inner positions of the 64 squares in a chess board, 
    replacing the boundary squares with the string ‘—-‘.'''

    # '----', (1, 1), (2, 1), (3, 1), (4, 1), (5, 1), (6, 1), '----'],
    
    # for i in range(8):
    #     for j in range(6):
    #         print(tuple(j,i))
    k = 1
    ls= [(j,i) for i in range(1,8) for j in range(7)]
    # print(ls)
    
    for line in range(7):
        print(ls[:8])


chess_board()