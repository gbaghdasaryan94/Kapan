x = int(input('x = '))
y = int(input('y = '))
z = int(input('z = '))

if x + y <= z or x + z <= y or y + z <= x:
    print('no such triangle')
elif x == y == z:
    print('the triangle is equilateral')
elif x == y != z or x == z != y or y == z != x:
    print('the triangle is isosceles')
else:
    print('the triangle is scalene')
