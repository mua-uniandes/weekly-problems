n = int(input())
strings = [input().strip() for _ in range(n)]

concatenated = [s+s for s in strings]
best = 1000000000
T = strings[0]
for i in range(len(T)):
    total_steps = 0
    for S in concatenated:
        steps = S.find(T)
        if steps == -1:
            best = -1
            break
        total_steps += steps
    if best == -1:
        break
    best = min(total_steps, best)
    T = T[1:]+T[:1]

print(best)