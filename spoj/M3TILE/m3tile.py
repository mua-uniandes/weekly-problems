def d(n):
    if n == 0:
        return 1

    f = [0] * (n+1)
    g = [0] * (n+1)
    f[0], f[1] = 1, 0
    g[0], g[1] = 0, 1
    
    for i in range(2, n+1):
        f[i] = f[i-2] + 2 * g[i-1]
        g[i] = f[i-1] + g[i-2]
    return f[n]

s = int(input())
while s != -1:
    print(d(s))
    s = int(input())