def operacion(linea):
    a = linea[0]
    b = linea[1]
    c = linea[2]
    d = linea[3]
    time = b
    sueno = 0
    if a > b:
        time = b
        sueno = b
        if c < d:
            time = -1
        else:
            while sueno < a:
                time += c
                sueno+=(c-d)
    return time

def solucion():
    testCases = int(input())
    soluciones = []
    for n in range(testCases):
        linea = list(map(int, input().split()))
        soluciones.append(operacion(linea))
    print(soluciones)
solucion()