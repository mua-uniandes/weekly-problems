t = int(input())
for i in range(t):
    whn = list(map(int, input().split()))
    w = whn[0]
    h = whn[1]
    n = whn[2]
    num = 1
    i = 2
    while (w % i == 0):
        num *= 2
        i *= 2
    i = 2
    while(h % i == 0):
        num *= 2
        i *= 2
    if num < n:
        print('NO')
    else:
        print('YES')