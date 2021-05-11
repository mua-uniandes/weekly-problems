def prueba(t):
    lista = []
    index = []
    for i in range(len(t)):
        if t[i]%2 == 0:
            print(1)
            print(i+1)
            return
        else:
            lista.append(t[i])
            index.append(i+1)
    if len(index) >= 2:
        print(2)
        print(index[0], index[1])
    else:
        print("-1")



t = input()
t = int(t)
for i in range(t):
    n = input()
    n = int(n)
    a = input().split()
    a = list(map(int,a))
    prueba(a)