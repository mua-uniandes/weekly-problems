import heapq
import math

def find(element):
    if parent[element] != element:
        parent[element] = find(parent[element])
    return parent[element]

def union(parentA, parentB):
    if rank[parentA] > rank[parentB]:
        parent[parentB] = parentA
        rank[parentA] += rank[parentB]
    else:
        parent[parentA] = parentB
        rank[parentB] += rank[parentA]

case = int(input())
idx = 1
while case != 0:
    points = []
    for _ in range(case):
        x, y = map(int, input().split())
        points.append((x, y))
    
    edges = []
    for u in range(case):
        for v in range(case):
            if u != v:
                distance = math.dist(points[u], points[v])
                edges.append((distance, u, v))
    
    parent = list(range(case))
    rank = [1] * case
    heapq.heapify(edges)
    max_jump = 0.0
    
    while find(0) != find(1):
        w, u, v = heapq.heappop(edges)
        pu, pv = find(u), find(v)
        if pu != pv:
            union(pu, pv)
            if w > max_jump:
                max_jump = w
    
    print(f"Scenario #{idx}")
    print(f"Frog Distance = {max_jump:.3f}\n")
    idx += 1
    l = input()
    case = int(input())