n = int(input())
import math
for i in range(n):
    n, m, k = map(int, input().split())
    # n mod k = 0
    c=n/k
    if c >= m:
        print(m)
    else:
        if n == k:
            print(0)
        else:
            jokers = m - c
            print(int(c - math.ceil(jokers/(k-1))))