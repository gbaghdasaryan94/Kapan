# 1. Create a Rectangle class. Rectangle should have: length and width.


class Rectangle:

    def __init__ (self, length, width):
        self._length = length
        self._width = width

    @property
    def length(self):
        return self._length

    @length.setter
    def length(self, new_length):
        self._length = new_length    


    def area(self):
        return self._length * self._width

    def perimeter(self):
        return 2 * (self._length + self._width)  

    def __repr__(self):
        return f'Length is {self._length}, Width is {self._width}, Area is {self.area()}, Perimeter is {self.perimeter()} '    

    def __str__(self):
        return f'Length is {self._length}, Width is {self._width}'


if __name__ == "__main__":
    
    rectangle = Rectangle(6, 9)
    print(repr(rectangle))
    print(str(rectangle))