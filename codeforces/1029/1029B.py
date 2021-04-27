n = int(input())
a = list(map(int,input().split()))[:n]
f = [0]*len(a)
ans = 0
for i in range(len(a)-1):
    x = -1
    if i == 0:
        x = 0
    else:
        x = f[i-1]
    if 2*a[i] >= a[i+1]:
        f[i] = x + 1
        if ans < x +1:
            ans = x+1
    else:
        f[i] = 0
print(ans+1)