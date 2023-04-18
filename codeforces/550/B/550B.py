n, l, r, x = map(int, input().split())
# n problems
# total = l min, r max
# x min diff
c = list(map(int, input().split()))
# c[i] is the difficulty of problem i


problemas = list(range(n))

import itertools
combinaciones = []
for i in range(2, n+1):
    combinaciones+=(list(itertools.combinations(problemas, i)))

def check_comb(comb, c, l, r, x):
    suma = 0
    minimo = c[comb[0]]
    maximo = c[comb[0]]
    for i in comb:
        suma += c[i]
        if c[i] < minimo:
            minimo = c[i]
        if c[i] > maximo:
            maximo = c[i]
    if suma >= l and suma <= r and maximo-minimo >= x:
        return True
    else:
        return False
    
count = 0
for comb in combinaciones:
    if check_comb(comb, c, l, r, x):
        count += 1
print(count)