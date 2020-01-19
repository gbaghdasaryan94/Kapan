def prime(number):

    for n in range(2,number):
        if not ( number % n ):
            return False
    return True
       
print([i for i in range(2,input("Enter a number greater than or equal 2: ")) if prime(i)])

