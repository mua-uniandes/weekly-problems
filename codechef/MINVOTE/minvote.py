t = int(input())
for x in range(t):
    n = int(input())
    minions = list(map(int, input().split()))
    votos = [0]*n
    for i in range(n):
        s = 0
        for j in range(i+1, n):
            if s <= minions[i]:
                votos[j] += 1
                s += minions[j]
            else:
                break
        s= 0
        for j in range(i-1, -1, -1):
            if s <= minions[i]:
                votos[j] += 1
                s += minions[j]
            else:
                break
    print(*votos)