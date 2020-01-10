# 10. Write a Python program to calculate a dog's age in dog's years.

human, text = int(input("Input a dog's age in human years: ")), "The dog's age in dog's years is"
print(text, int(2 * 10.5 + ((human-2)*4))) if human > 2 else print(text , human * 10.5)    

