import math
n=int(input())
for i in range(n):
    line = input().split(" ")
    a = int(line[0])
    b = int(line[1])
    if b<a:
        b = b * math.ceil(a / b)
    x = math.ceil(b / a)
    print(x)