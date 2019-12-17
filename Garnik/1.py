# 1. Create a Rectangle class. Rectangle should have: length and width.


class Rectangle(length, width):

    def __init__ (self, length, width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

if __name__ == "__main__":
    diamentions = Rectangle(7,6)
    
    print(Rectangle.area)    