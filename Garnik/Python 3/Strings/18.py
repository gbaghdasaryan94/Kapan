
# 18. Check if given set of moves is circular or not. 
# The move is circular if its starting and ending coordinates are the same. 
# The moves can contain instructions to move one unit in same direction (M), 
# to change direction to left of current direction (L) 
# and to change direction to right of current direction (R).


# N = 0 direction up, change only +y
# E = 1 quarther right, change only +x
# S = 2 quarther down, change only -y
# W = 3 quarther left , change only -x 

string = 'MRMRMRM'

x, y, direction = 0,0,0

for i in string:
    if i == 'R':
        direction = (direction + 1) % 4 
        # 2
    elif i == 'L':
        direction = (4 + direction - 1) % 4    
        #  3 
    else:
        i == 'M'
        if direction == 0:
            y += 1
        elif direction == 1:
            x += 1
        elif direction == 2:
            y -= 1
        else:
            # direction == 3:
            x -= 1

print("set of moves is circular") if x == y == 0 else print("set of moves is not circular")
    











