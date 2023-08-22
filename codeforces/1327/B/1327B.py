from sys import stdin, stdout

def main():
    t = int(stdin.readline()) # casos de prueba
    ans = []
    for i in range(t):
        n = int(stdin.readline()) # numero de princesas
        princesses = {i:0 for i in range(1,n+1)}
        princes = {i:False for i in range(1,n+1)}
        for j in princesses.keys():
            preferences = stdin.readline().strip().split(' ')
            emparejated = False
            p = 1
            while p < len(preferences) and not emparejated:
                if not princes[int(preferences[p])]: # si el principe no ha sido seleccionado
                    princes[int(preferences[p])] = True # marcar al principe como emparejado
                    princesses[j] = int(preferences[p]) # asignarle a la princesa el principe
                    emparejated = True
                p += 1
        
        k = 1
        princess_empty = '0'
        optimal = True
        while k <= n and optimal:
            if princesses[k] == 0:
                optimal = False
                princess_empty = str(k)
            k += 1

        k = 1
        princes_empty = '0'
        optimal = True
        while k <= n and optimal:
            if princes[k] == 0:
                optimal = False
                princes_empty = str(k)
            k += 1
            
        ans.append('OPTIMAL\n' if princess_empty == '0' and princes_empty == '0' else f'IMPROVE\n{princess_empty} {princes_empty}\n')
    for a in ans:
        stdout.write(a)

main()