x = int(input())
t=x
fr=[]
sc=[]
td=[]
for i in range(3):
    temp=input().split(" ")
    if i==0:
        fr=list(map(int, temp))
    if i==1:
        sc=list(map(int, temp))
    if i==2:
        td=list(map(int, temp))
frS=sorted(fr)
scS=sorted(sc)
tdS=sorted(td)
res=[]
if t-1==len(sc):
    err=frS[-1]
    for i in range(t-1):
        if frS[i] != scS[i]:
            err=frS[i]
            break
    print(err)
if t-2==len(td):
    err=scS[-1]
    ##print(scS)
    for i in range(t-2):  
        if scS[i] != tdS[i]:
            err=scS[i]
            break
    print(err)