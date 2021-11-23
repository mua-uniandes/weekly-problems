nTests = int(input())
for _ in range(nTests):
    m = int(input())
    matrix = [[0 for i in range(m)] for j in range(2)]
    for i in range(2):
        matrix[i] = list(map(int, input().split()))
    ans = float('inf')
    sum1, sum2 = 0, 0
    for i in range(m):
        sum1 += matrix[0][i]
    for i in range(m):
        sum1 -= matrix[0][i]
        ans = min(ans, max(sum1, sum2))
        sum2 += matrix[1][i]
    print(ans)