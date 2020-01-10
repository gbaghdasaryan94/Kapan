# 20. Given a string, find all possible palindromic substrings in it.

string = "ababac"
combinations = []
# get all substrings from a given string
for i in range (len(string)):
     for j in range(i,len(string)):
        if string[i:j+1] not in combinations:
            combinations.append((string[i:j+1]))

# check which substrings are palindrome
for item in combinations:
    if item == item[::-1]:
        print(item)





