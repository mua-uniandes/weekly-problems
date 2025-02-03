import sys
input = sys.stdin.read
data = input().split()

idx = 0
t = int(data[idx])
idx += 1
matrices = []
for _ in range(t):
    n = int(data[idx])
    idx += 1
    
    polygon = []
    for _ in range(n):
        row = data[idx]
        polygon.append(row)
        idx += 1
    matrices.append(polygon)
    

    
for i in range(0, len(matrices)):
    tamano = len(matrices[i][0])
    string_of_ones = '1' * tamano
    matrices[i].append(string_of_ones)
    for j in range(0, len(matrices[i])):
        matrices[i][j] = matrices[i][j] + '1'

def problema(matrices):
    
    respuesta = []
    n = len(matrices)
    
    for i in range(0, n):
        tablero = matrices[i]
        llave = True
        
        for j in range(0, len(tablero) - 1):
            fila = tablero[j]
            
            for k in range(0, len(tablero[j]) - 1):
                valor = fila[k]
                
                if valor == '1':
                    if tablero[j+1][k] == '1' or tablero[j][k+1] == '1':
                        continue
                    else:
                        llave = False
                        break
        if not llave:
            respuesta.append('NO')
        else:
            respuesta.append('YES')    
            
    return respuesta  

resultados = problema(matrices)
for resultado in resultados:
    print(resultado)