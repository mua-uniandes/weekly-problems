while True:
    a = int(input())
    if a == 0:
        break
    matriz = []
    for i in range(a):
        matriz.append([a for i in range(a)])
    for j in range(a-1):
        lista =  input().split(" ")
        for z in range(0,len(lista) -1,2):
            matriz[int(lista[z])-1][int(lista[z+1])-1] = j +1
    if a > 1:
        done = False
        c = "wrong"
        for i in range(a): 
            for j in range(a):
                b = False
                if j + 1 < a and matriz[i][j] == matriz[i][j+1]:
                    b = True
                if j  >= 1 and matriz[i][j] == matriz[i][j-1]:
                    b = True
                if i + 1 < a and matriz[i][j] == matriz[i+1][j]:
                    b = True
                if i >= 1  and matriz[i][j] == matriz[i-1][j]:
                    b = True
                if not b:
                    done = True
                    i = a + 1
                    break
        if not done:
            c = "good"
        print(c)
    else:
        print("good")