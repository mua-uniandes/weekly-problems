import sys
def _input():
    return sys.stdin.readline().strip()

def lcs(a, b):
    n = len(a)
    dp = [[0 for _ in range(n+1)] for __ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1, n+1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][n]

for _ in range(int(_input())):
    int(_input())
    s = _input()
    reverse = s[::-1]
    print(lcs(s, reverse)//2)