import math

def quad_equation(a,b,c):
    '''Quadratic function : (a * x^2) + b*x + c'''

    x1 = (-b - math.sqrt(b**2 - 4*a*c))/(2*a)
    x2 = (-b + math.sqrt(b**2 - 4*a*c))/(2*a)
    return x1,x2

print(quad_equation(5,20,10))