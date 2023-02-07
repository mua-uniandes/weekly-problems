def problemaA ():
    lst_word = [] #lista donde meto cada una de las letras
    lst_og = [] #lista original
    saludo = ['h', 'e', 'l', 'l', 'o']
    counter = 0
    respuesta = 'NO'

    cadena = input()

    for i in cadena:
        lst_og.append(i)
        counter += 1
    
    for i in range(len(lst_og)):
        if len(saludo) != 0:
            if saludo[0] == lst_og[i]:
                lst_word.append(lst_og[i])
                saludo.remove(lst_og[i])

    if len(saludo) == 0:
        respuesta = "YES"


    print(respuesta)
problemaA()