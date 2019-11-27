s = '_, we have a _.'
l = ['Houston', 'problem']

for i in l:
    s = s[:s.index('_')] + i + s[s.index('_') + 1:]
    
print(s)
