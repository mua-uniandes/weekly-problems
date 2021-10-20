tests=int(input())
for w in range(tests):
    t=input()
    #print('t',t)
    cent=True
    for i in range(len(t)-1):
        if t[i]!=t[i+1]:
            cent=False
            i=len(t)-1
    if cent:
        print(t+'\n')
    else:
        print('01'*len(t)+'\n')