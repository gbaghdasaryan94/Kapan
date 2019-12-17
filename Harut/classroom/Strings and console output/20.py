s = input('enter a string: ').strip()
p = []

for j in range(len(s)):
    for i in range(len(s)):
        if s[j:len(s) - i] == ''.join(reversed(s[j:len(s) - i])):
            p.append(s[j:len(s) - i])      
                  
p = list(dict.fromkeys(p))
print(','.join(p))
