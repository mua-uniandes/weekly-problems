N = int(input())
A = [tuple(map(int, input().split())) for i in range(N)]
ans = 0
for i in range(N):
    for j in range(i):
        if abs(A[i][1] - A[j][1]) <= abs(A[i][0] - A[j][0]):
            ans += 1
print(ans)