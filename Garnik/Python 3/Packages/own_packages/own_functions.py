def prime(number):
    '''Check if the number is prime'''

    for n in range(2,number):
        if not ( number % n ):
            return False
    return True


def quad_equation(a,b,c):
    '''Quadratic function : (a * x^2) + b*x + c'''

    x1 = (-b - math.sqrt(b**2 - 4*a*c))/(2*a)
    x2 = (-b + math.sqrt(b**2 - 4*a*c))/(2*a)
    return x1,x2


def float_to_ratio(number):
    
    '''3. Write a Python program to convert a float to ratio.'''
    
    spot = str(number).find(".")
    first = int(str(number)[:spot]+str(number)[spot+1:])
    second = 10**len(str(number)[spot+1:]) 
    hamarich = first//euclidean(first,second)
    haytarar = second//euclidean(first,second)
    return f'{hamarich}/{haytarar}'


def euclidean(number1, number2):
    
    '''Check the highest devisible number'''

    num1 = max(number1, number2)
    num2 = min(number1, number2)

    if num1 % num2 ==0:
        return num2
    else:
        number2 = num1 % num2    
        number1 = num2
        return euclidean(number1, number2)    

