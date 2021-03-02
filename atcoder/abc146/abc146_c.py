A, B, X = map(int,input().split())
max_integer = 10**9 + 1
min_integer = 0

#Podemos encontrar N usando una especie de busqueda binaria.
#Si tengo mas plata (X) que lo que vale n, entonces busco un integer mas grande 
#---> Convierto min_integer en n
#Si tengo menos plata, busco un numero menor
while max_integer - min_integer > 1:
	n = (max_integer + min_integer)//2
	if (A*n + B*len(str(n))) <= X:
		min_integer = n
	else:
		max_integer = n

if (A*n + B*len(str(n))) <= X:
	print(min(n, 10**9))

else:
	print(min_integer)