# def addBorder(picture):
#     str = []
#     str.append(''.join(["*" for v in range(len(picture[0])+2)]))
#     for val in picture:
#         str.append('*'+val+'*')
#     str.append(''.join(["*" for v in range(len(picture[0])+2)]))
#
#     return str

def addBorder(picture):
    length=len(picture[0])+2
    return ["*"*length]+[x.center(length,"*") for x in picture]+["*"*length]

print(addBorder([v for v in input("Enter array : ").split()]))