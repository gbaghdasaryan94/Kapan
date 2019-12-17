# Check if given set of moves is circular or not. 
# The move is circular if its starting and ending coordinates are the same. 
# The moves can contain instructions to move one unit in same direction (M), 
# to change direction to left of current direction (L) 
# and to change direction to right of current direction (R).

st = input("Enter string consisting of letters M R L: ").upper()
x,y,d = 0,0,0

for i in st:

    if i == "M":
        if d == 0:
            y += 1
        elif d == 2:
            y -= 1
        elif d == 1:
            x += 1
        else:
            x -=1
    
    elif i == "L":
        if d == 0:
            d = 3
        else:
            d -= 1

    elif i == "R":
        if d == 3:
            d = 0
        else:
            d +=1

    else:
        pass

print(x == 0 and y == 0)