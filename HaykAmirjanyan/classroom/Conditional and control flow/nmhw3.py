# Write a Python program to guess a number between 1 to 9.
n = 5
while True:
    if(int(input("Enter number between 1 to 9.: ")) == n):
        print("Well guessed!")
        quit()