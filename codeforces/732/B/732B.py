n, k = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

b = 0

if n > 1:
    for i in range(n - 1):
        if a[i] + a[i + 1] < k:
            extra = k - (a[i] + a[i + 1])
            a[i + 1] += extra
            b += extra

print(b)
print(' '.join([str(i) for i in a]))