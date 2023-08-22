T=int(input())
for i in range(T):
    n=int(input())
    x=input()
    c1=0
    c2=0
    c3=0
    lista=[False]*n
    for z in range(n):
        if x[z]=='-':
            c1+=1
            lista[z]=True
            lista[(z+1)%n]=True
        elif x[z]=='<':
            c2+=1
        else:
            c3+=1
    if c1+c2==n or c1+c3==n:
        print(n)
    else:
        print(lista.count(True))