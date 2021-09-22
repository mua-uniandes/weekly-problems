line=input().split(" ")
n= int(line[0])
m = int(line[1])
vect=[]
cont=[0]*n
for t in range (n):
    vect.append([])
for i in range (m):
    line=input().split(" ")
    a= int(line[0])
    b = int(line[1])
    cont[a - 1]+=1
    cont[b - 1] += 1
    vect[a - 1].append(b-1)
    vect[b - 1].append(a-1)
cent=True
tot=0
while cent:
    L=[]
    for i in range(n):
        if cont[i]==1:
            L.append(i)
    if  len(L)==0:
        cent=False
        print(tot)
    else:
        for l in L: 
            for elem in vect[l]:
                cont[elem]-=1
                cont[l]=0
        tot+=1