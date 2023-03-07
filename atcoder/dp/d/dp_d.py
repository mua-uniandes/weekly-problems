N, W = map(int, input().split())
values = []
weights = []

for i in range(N):
    w, v = map(int, input().split())
    values.append(v)
    weights.append(w)

dp = [[0 for i in range(W+1)] for j in range(N+1)]

for i in range(N):
    for j in range(W+1):
        if j >= weights[i]:
            dp[i+1][j] = max(dp[i][j], dp[i][j-weights[i]]+values[i])
        else:
            dp[i+1][j] = dp[i][j]

print(dp[N][W])