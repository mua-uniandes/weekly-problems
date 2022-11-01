n = int(input())
h = {}
for _ in range(0, n):
    m = input().replace("\n", "")
    if m not in h:
        h[m] = 0
    h[m] += 1

maxi = 0
l = ""
for k,v in h.items():
    if v > maxi:
        maxi = v
        l = k

print(l)