X = input()
M = int(input())
X_list = [int(i) for i in X]
d = max(X_list)
max_value = 10**18+1
ok = 0

if len(X) == 1:
    if int(X) <= M:
        print(1)
    else:
        print(0)
    exit()
# BINARY SEARCH
X_list.reverse()
while abs(ok-max_value) > 1:
    c = (ok+max_value)//2
    num = 0
    p = 0
    for x in X_list:
        num += x*(pow(c, p))
        p += 1
    if num <= M:
        ok = c
    else:
        max_value = c

ans = max(ok-d, 0)
print(ans)