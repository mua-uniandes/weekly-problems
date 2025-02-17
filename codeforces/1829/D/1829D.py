times = int(input())

def cosa(vaino):
    pila = int(vaino[0])
    target = int(vaino[1])

    if target > pila:
        return "NO"

    if target%2 != 0 and pila%2 == 0:
        return "NO"
    
    if pila == target:
        return "YES"
    
    return "YES" if recur(pila, target) else "NO"
    


def recur(nuevovalor, target):
    var1 = nuevovalor / 3
    var2 = nuevovalor * 2 / 3
    
    if var1 == target or var2 == target:
        return True
    elif var1 < target and var2 < target:
        return False
    else:
        return recur(var1, target) or recur(var2, target)


valors = []
for i in range(0, times):
    vaino = input().split(" ")
    otra = [
        int(vaino[0]),
        int(vaino[1])
    ]
    valors.append(otra)
    
for i in range(0, times):
    print(cosa(valors[i]))

        
