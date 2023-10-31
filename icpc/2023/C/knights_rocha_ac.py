from sys import stdin
from collections import deque

MAX,INF = 1000,float('inf')
dist    = [ [ None for _ in range(MAX) ] for _ in range(MAX) ]
N       = None
delta   = [ (-1, -2), (-1, 2), (-2, -1), (-2, 1), (1, -2), (1, 2), (2, -1), (2, 1) ]

def solve(rowa, cola, rowb, colb):
  ans = None
  if (rowa+cola)%2==(rowb+colb)%2:
    for r in range(N):
      for c in range(N):
        dist[r][c] = INF
    queue = deque() ; queue.append((rowa, cola)) ; dist[rowa][cola] = 0
    while len(queue)!=0 and dist[rowb][colb]==INF:
      r,c = queue.popleft()
      for dr,dc in delta:
        tmpr,tmpc = r+dr,c+dc
        if 0<=tmpr<N and 0<=tmpc<N and dist[tmpr][tmpc]==INF:
          queue.append((tmpr, tmpc)) ; dist[tmpr][tmpc] = dist[r][c]+1
    if dist[rowb][colb]%2==0: ans = dist[rowb][colb]>>1
  return ans

def main():
  global N
  N,a,b,c,d = map(int, stdin.readline().split())
  while N+a+b+c+d!=0:
    ans = solve(a, b, c, d)
    print(ans if ans!=None else '*')
    N,a,b,c,d = map(int, stdin.readline().split())

main()
