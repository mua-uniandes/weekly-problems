x,y=map(int,input().split(" "))

matriz=[]
for i in range(x):
    row=[int(x) for x in input().split(" ")]
    matriz.append(row)

total=0

for i in matriz:
    
    l,r=False,False
    count=0
    for j in range(len(i)):
        if i[j]==1:
            if not l:
                l=True
                total+=count
            elif not r:
                r=True
                total+=count*2
            else:
                total+=count*2
            count=0
         
        else:
             count+=1

    if l:

        total+=count







for j in range(len(matriz[0])):
   
    count=0
    t,b=False,False
    for i in range(len(matriz)):
        if matriz[i][j]==1:
            
            if not t:
                t=True
                total+=count
            elif not b:
                b=True
                total+=count*2
            else:
                total+=count*2
            count=0
         
        else:
            count+=1
    
    if t:

        total+=count
    


print(total)