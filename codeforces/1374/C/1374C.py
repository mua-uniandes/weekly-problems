from sys import stdin, stdout

n = int(stdin.readline().replace("\n", ""))

for _ in range(0, n):
    m = int(stdin.readline().replace("\n", ""))
    brackets = stdin.readline().replace("\n", "")
    r = m // 2
    l = []
    c = 0
    for i in range(0, len(brackets)):
        if brackets[i] == '(': l.append(brackets[i])
        elif len(l) == 0: c+=1
        else: l.pop(-1)

    print(c)