N, M = map(int, input().split())
S = [int(i) for i in input()]
S.reverse()

x = 0
respuesta = []
condicion = True
while condicion:
	paso = x+M
	if paso >= N:
		respuesta.append(N-x)
		condicion = False
	else:
		while S[paso]:
			paso -= 1
		if paso == x:
			respuesta = [-1]
			break
		respuesta.append(paso-x)
		x = paso
respuesta.reverse()
print(*respuesta)