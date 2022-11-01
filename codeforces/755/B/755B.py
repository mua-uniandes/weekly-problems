from sys import stdin, stdout

n, m = map(int, stdin.readline().replace("\n", "").split(" "))

if n > m: stdout.write("YES")
elif n < m: stdout.write("NO")
elif n == m:
    n2 = list()
    m2 = list()
    for n in range(0, n):
        n2.append(stdin.readline().replace("\n", ""))
    for n in range(0, m):
        m2.append(stdin.readline().replace("\n", ""))
    intr = set(set(n2).intersection(set(m2)))
    if len(intr) % 2 == 0:
        print("NO")
    else:
        print("YES")