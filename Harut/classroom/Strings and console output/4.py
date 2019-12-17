s1 = input('s1 = ')
s2 = input('s2 = ')
s3 = s2[:2] + s1[2:] + ' ' + s1[:2] + s2[2:]
print(f'new string is: {s3}')
