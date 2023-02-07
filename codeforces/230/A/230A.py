s, n = map(int, input().split())
dragons = []
for i in range(n):
    x, y = map(int, input().split())
    dragons.append([x, y])
dragons.sort()
win = True
for i in range(n):
    if s > dragons[i][0]:
        s += dragons[i][1]
    else:
        win = False
        break

if win:
    print("YES")
else:
    print("NO")