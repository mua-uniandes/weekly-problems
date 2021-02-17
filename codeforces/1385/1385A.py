t = int(input())
for i in range(t):
    xyz = list(map(int,input().split()))
    xyz.sort()
    if xyz[1] == xyz[2]:
        print('YES')
        print(xyz[2],xyz[0],xyz[0])
    else:
        print('NO')