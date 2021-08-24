n=int(input())
line=input().split(" ")
line=list(map(int,line))
line.sort()
i=0
cont=0
j=1
while i<n:
    if int(line[i])>=j:
        cont+=1
        i+=1
        j+=1
    else:
        i+=1
print(cont)