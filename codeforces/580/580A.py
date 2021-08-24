long = input()
lista = input().split(" ")
c = 1
mayor = 0
i = 0
while i <int(long):

    if i+1 < int(long):
        actual = int(lista[i])
        siguiente = int(lista[i+1])
        if  siguiente >= actual :
            c +=1
        elif  c >= mayor: 
            mayor = c 
            c = 1
        else:
            c = 1
    i+=1
print(mayor)