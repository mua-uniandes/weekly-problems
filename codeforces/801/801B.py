x = input()
z = input()
y=""
for i in range(0, len(z)):
    if x[i] < z[i]:
        print(-1)
        break
    else:
        y += z[i]
    if i == len(z)-1:
        print(y)