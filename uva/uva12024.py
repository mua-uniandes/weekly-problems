a = [0]*13
fact = [0]*13
a[0] = 1
a[1] = 0
fact[1] = 1
for i in range(2,13):
    a[i] = (i-1)*(a[i-1] + a[i-2])
    fact[i] = i*fact[i-1]

cases = int(input())
for i in range(0,cases):
    hats = int(input())
    print(f'{a[hats]}/{fact[hats]}')
    