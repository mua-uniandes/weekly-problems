import heapq
import sys

def dijkstra(n, m, edges):
    graph = {i: [] for i in range(1, n + 1)}
    
    for a, b, w in edges:
        graph[a].append((b, w))
        graph[b].append((a, w))
    
    dist = {i: sys.maxsize for i in range(1, n + 1)}
    dist[1] = 0
    
    previous = {i: None for i in range(1, n + 1)}
    
    pq = [(0, 1)]
    
    while pq:
        current_dist, current_node = heapq.heappop(pq)
        
        if current_dist > dist[current_node]:
            continue
        
        for neighbor, weight in graph[current_node]:
            distance = current_dist + weight
            
            if distance < dist[neighbor]:
                dist[neighbor] = distance
                previous[neighbor] = current_node
                heapq.heappush(pq, (distance, neighbor))
    
    if dist[n] == sys.maxsize:
        return -1, []
    
    path = []
    current = n
    while current is not None:
        path.append(current)
        current = previous[current]
    
    path.reverse()
    
    return dist[n], path

n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]

cost, path = dijkstra(n, m, edges)

if cost == -1:
    print(-1)
else:
    print(" ".join(map(str, path)))
