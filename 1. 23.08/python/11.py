space = 2
c = 1
for i in range(1,8):
    for i in range (0,space):
        print(' ',end="")
    for i in range(0, c):
        print('*',end="")
    print('\n')
    if space > 0:
        space -= 1
    if c < 5:
        c += 2;
