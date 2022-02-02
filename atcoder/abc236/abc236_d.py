import sys

def calculate():
    if len(pairs) == n:
        affinity = 0
        for pair in pairs:
            affinity ^= affinities[pair[0]][pair[1]]
        return affinity
    
    l = -1
    for i in range(1, 2*n):
        if not used[i]:
            l = i
            break
        
    used[l] = True
    affinity = 0
    for i in range(1, 2*n):
        if not used[i]:
            pairs.append([l, i]) 
            used[i] = True
            affinity = max(affinity, calculate())
            pairs.pop() 
            used[i] = False
        
    used[l] = False
    return affinity

n = int(input())
affinities = [[ -1 for i in range(2*n-1)] for j in range(2*n-1)]
pairs = []
used = [False for i in range(20)]

for i in range(0, 2*n-1):
    values = [int(x) for x in input().split(" ")]
    for j in range(0, len(values)):
        affinities[i][j] = values[j]
print(calculate())


