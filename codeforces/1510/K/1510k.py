# Leer la primera línea que contiene el número n
n = int(input())

# Leer la segunda línea que contiene 2n números enteros
line = input().strip()

# Convertir la segunda línea en una lista de enteros
permutation = list(map(int, line.split()))

def permutaciones(permutaciones):
    if esta_ordenada(permutaciones):
        return 0
    listaCambiada1 = []
    listaCambiada1 = swapUno(permutaciones)
    if esta_ordenada(listaCambiada1):
        return 1
    ValorUno = 0
    LlaveUno = True
    for i in range(0, n):
        if LlaveUno:
            if i % 2 == 0:
                listaCambiada1 = swapDos(listaCambiada1)
                if esta_ordenada(listaCambiada1):
                    ValorUno = i + 2
                    LlaveUno = False
            else:
                listaCambiada1 = swapUno(listaCambiada1)
                if esta_ordenada(listaCambiada1):
                    ValorUno = i + 2
                    LlaveUno = False
        else:   
            break
            
    listaCambiada2 = []
    listaCambiada2 = swapDos(permutaciones)
    if esta_ordenada(listaCambiada2):
        return 1
    ValorDos = 0
    LlaveDos = True
    for i in range(0, n):
        if LlaveDos:
            if i % 2 == 0:
                listaCambiada2 = swapUno(listaCambiada2)
                if esta_ordenada(listaCambiada2):
                    ValorDos = i + 2
                    LlaveDos = False
            else:
                listaCambiada2 = swapDos(listaCambiada2)        
                if esta_ordenada(listaCambiada2):
                    ValorDos = i + 2
                    LlaveDos = False
        else:
            break
    if ValorUno == 0 and ValorDos == 0:
        return -1
    else:
        if ValorUno == 0:
            return ValorDos
        if ValorDos == 0:
            return ValorUno
        return min(ValorUno, ValorDos)

def swapUno(lista):
    NuevaLista = []
    for i in range(0, len(lista) ):
        if i%2 == 0:
            NuevaLista.append(lista[i+1])
        else:
            NuevaLista.append(lista[i-1])
    return NuevaLista

def swapDos(lista):
    NuevaLista = [0] * len(lista)
    for i in range(0, n):
        NuevaLista[i] = lista[n + i]
        NuevaLista[n + i] = lista[i]
    return NuevaLista

def esta_ordenada(lista):
    for i in range(len(lista) - 1):
        if lista[i] > lista[i + 1]:
            return False
    return True

print(permutaciones(permutation))

