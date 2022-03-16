
while input():     
    arreglo = list(map(int,input().split()))
    ya=False
    max=1
    cantidad=0
    for j in range(len(arreglo)-1):
        for i in range(j,len(arreglo)-1):
            if arreglo[i]<arreglo[i+1]:
                cantidad=cantidad+1
                print(cantidad, " ", i)
            if (arreglo[i]>=arreglo[i+1] and ya==True) or i==(len(arreglo)-2):
                cantidad=cantidad+1
                print(cantidad, " ", i)
                if cantidad > max:
                    max=cantidad
                cantidad=0
                ya=False
                break
            elif arreglo[i]>=arreglo[i+1] and ya==False:
                cantidad=cantidad+1
                ya=True
    print(max)