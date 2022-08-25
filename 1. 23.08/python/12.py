space = 5
c = 1
for i in range(c,7):
    for i in range (0,space):
        print(' ',end="")
    for i in range(0, c):
        print('*',end="")
    print('\n')
    space -= 1
    c+=2
