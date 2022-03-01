while True:
    n, d = [int(x) for x in input().split()]

    if n == 0 and d == 0:
        break

    res = 1
    for i in range(d):
        res = res*n

    print(res)