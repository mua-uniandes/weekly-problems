a, b, c = [int(x) for x in input().split()]

z = (int)(1/2 * (c+b-a))
y = (int)(b - z)
x = (int)(a - y)

# revisamos que sea válido
imposible = False

# no es divisible entre 2
if (c+b-a) % 2 != 0:
    imposible = True
elif (a+b+c) % 2 != 0:
    imposible = True
elif (x < 0 or y < 0 or z < 0):
    imposible = True

if (imposible):
    print("Impossible")
else:
    print(y, z, x)