pal = input()

mul = 1

def fib(n):
    n-=1
    if n <= 0:
        return 1
    elif n == 1:
        return 2

    a, b, c = 1,2,1

    for _ in range(2, n + 1):
        c = a + b
        a = b
        b = c

    return c


i = 0

fake = False

while i < len(pal):
    if pal[i]=="n":
        # contar cuantas n seguidas hay
        c = 0
        while i < len(pal) and pal[i]=="n":
            c+=1
            i+=1
        i-=1

        mul *= fib(c)
    
    elif pal[i]=="u":
        c = 0
        while i < len(pal) and pal[i]=="u":
            c+=1
            i+=1
        i-=1

        mul *= fib(c)
    
    elif pal[i]=="m" or pal[i]=="w":
        fake = True
        break
    
    i+=1

if fake:
    print(0)
else:

    print(mul%(10**9+7))
