# 19. Given a positive number, convert the number into corresponding excel column name.


number = 335

column = ""
for i in range(1,number):
    column = chr(64 + number //26) + chr(64 + number % 26)
    if number // 26 == 1:
        column = chr(64 + number //26)
    elif number % 26 ==0:
        column = chr(64 + number //26 - 1) + chr(90)
print(column)    
   