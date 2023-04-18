n, m = map(int, input().split())
# n cities, m pairs of cities
valid_city = list(range(1, n+1))

for _ in range(m):
    a, b = map(int, input().split())
    if a in valid_city:
        valid_city.remove(a)
    if b in valid_city:
        valid_city.remove(b)

print(n-1)
city = valid_city[0]
for i in range(1, n+1):
    if i != city:
        print(city, i)