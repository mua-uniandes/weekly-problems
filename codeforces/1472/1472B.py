def dulceDivision():
    t = int(input())
    respuesta = []
    for x in range(0, t):
        candies = int(input())
        lista = (input().split(" "))
        c = 0
        bool = True
        for l in lista:
            if l == "1":
                c += 1
                bool = False
        if c%2 == 0 and (not bool):
            respuesta.append("YES")
        elif bool and len(lista)%2==0 and c%2==0:
            respuesta.append("YES")
        else:
            respuesta.append("NO")
    for e in respuesta:
        print(e)

if __name__ == '__main__':
    dulceDivision()