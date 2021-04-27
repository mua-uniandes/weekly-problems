i1 = input()
i2 = input()

i1 = i1.split(" ")
tam = int(i1[0])
repl = int(i1[1])


lv=0

for i in range(1, tam+1):
    
    cutOri = i2[:tam-int(i)]
    cutPast = i2[:i]
    
    nCad = cutOri+cutPast

    if nCad == i2 and i != tam:
        lv = i
    

nfinal = i2
for j in range(1,repl):
    part = i2[lv:]
    nfinal = nfinal+part

print(nfinal)