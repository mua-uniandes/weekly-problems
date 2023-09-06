n, w = map(int, input().split())

weights = []
values = []

for i in range(n):
    a, b = map(int, input().split())
    weights.append(a)
    values.append(b)

dp = [[float("inf") for i in range(sum(values)+1)] for j in range(n+1)]

dp[0][0] = 0

for i in range(n):
    for j in range(sum(values)+1):
        if j >= values[i]:
            dp[i+1][j] = min(dp[i][j], dp[i][j-values[i]]+weights[i])
        else:
            dp[i+1][j] = dp[i][j]

ans = 0

for i in range(sum(values)+1):
    if dp[n][i] <= w:
        ans = i

print(ans)

