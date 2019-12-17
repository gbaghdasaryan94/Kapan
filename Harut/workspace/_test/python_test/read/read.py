r = open('hello.c', 'r').read().split('\n')
r = ''.join(r).strip('  ')
print(r)