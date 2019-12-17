from string import ascii_lowercase

alpha = set(ascii_lowercase)
s = set(input('enter a string: ').lower())
print(s >= alpha)
