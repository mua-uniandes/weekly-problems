def solve_case(n, li):
    
    a = []
    for i in li:
        a.append(i-1)
    visited = [False]*n
    cnt2 = 0
    cnt_non2 = 0

    for i in range(n):
        if not visited[i]:
            current = i
            chain = {}
            while True:
                chain[current] = len(chain)
                visited[current] = True
                nxt = a[current]
                if nxt in chain:
                    cycle_length = len(chain) - chain[nxt]
                    if cycle_length == 2:
                        cnt2 += 1
                    else:
                        cnt_non2 += 1
                    break
                if visited[nxt]:
                    break
                current = nxt

    maximum = cnt2 + cnt_non2
    minimum = cnt_non2 + (1 if cnt2 > 0 else 0)
    return minimum, maximum

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    mi, ma = solve_case(n, a)
    print(mi, ma)