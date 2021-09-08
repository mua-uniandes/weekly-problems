import math
n=int(input())
for i in range (n):
    line=input().split(" ")
    a= int(line[0])
    b = int(line[1])
    if b>a:
        tmp=a
        a=b
        b=tmp
    cent = True
    x=a/b
    if x != math.ceil(x):
        print(-1)
        cent=False
    cont=0
    while cent:
        if (b==a):
            print(cont)
            cent=False
        elif a>=b*8:
            b=b*8
            cont+=1
        elif a>=b*4:
            b = b *4
            cont += 1
        elif a >= b * 2:
            b = b * 2
            cont += 1
        else:
            print(-1)
            cent = False