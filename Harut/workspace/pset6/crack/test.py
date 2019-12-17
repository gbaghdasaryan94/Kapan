import crypt

key = 'PasS'
salt = '50'
h = crypt.crypt(key, salt)
print(h)