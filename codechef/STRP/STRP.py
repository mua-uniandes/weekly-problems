from sys import stdin,stdout

t=int(stdin.readline())
for i in range(t):
    n=int(stdin.readline())
    s=list(stdin.readline())
    pos=0
    total=0
    while pos<n:
        
        if pos+1<n and s[pos]==s[pos+1]:
            total+=1
            pos+=2
        else:
            total+=1
            pos+=1
    print(str(total))