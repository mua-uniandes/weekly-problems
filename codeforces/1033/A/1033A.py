def king_space():
    n = int(input(''))
    a1, a2 = [int(i) for i in input('').split(' ')] #Reina
    b1, b2 = [int(i) for i in input('').split(' ')] #Rey
    c1, c2 = [int(i) for i in input('').split(' ')] #Objetivo


    if (b1 < a1 and c1 < a1) or (b1 > a1 and c1 > a1):
        if (b2 < a2 and c2 < a2) or (b2 > a2 and c2 > a2):
            return 'YES'

    return 'NO'

print(king_space())
