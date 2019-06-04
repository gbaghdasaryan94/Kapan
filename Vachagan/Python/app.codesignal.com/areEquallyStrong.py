def areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight):
    return yourLeft==friendsLeft and yourRight==friendsRight or yourLeft==friendsRight and yourRight==friendsLeft

print(areEquallyStrong(int(input("yourLeft : ")),int(input("yourRight : ")),int(input("friendsLeft : ")),int(input("friendsRight : "))))