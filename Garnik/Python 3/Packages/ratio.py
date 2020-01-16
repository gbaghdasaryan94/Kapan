def float_to_ratio(number):
    
    '''3. Write a Python program to convert a float to ratio.'''
    
    spot = number.find(".")
    first = int(number[:spot]+number[spot+1:])
    second = 10**len(number[spot+1:]) 
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

if __name__ == "__main__":

    print(float_to_ratio(str(input("Please enter a number: "))))