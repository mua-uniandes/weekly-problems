inp = input()

inp = list(inp)
tam = len(inp)


cumple = True


for i in range(0,tam,2):


    
    islow2 = inp[i].islower()
    
    if islow2 != True:
        cumple = False
        break
    
    
if cumple == True:
    
    for j in range(1,tam,2):
        
        isUpp = inp[j].isupper()
        
        if isUpp != True:
            cumple = False
            break
    
if cumple == True:
    print("Yes")
else:
    print("No")
