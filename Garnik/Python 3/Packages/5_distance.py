import math

def coordinates(x1,y1):
    print(x1[1])
    print((x1[1]-x1[0])**2)
    print((y1[1]-y1[0])**2)
    print((x1[1]-x1[0])**2 + (y1[1]-y1[0])**2)


    return math.sqrt((x1[1]-x1[0])**2 + (y1[1]-y1[0])**2)

print(coordinates([23.5, 67.5], [25.5, 69,5]))    