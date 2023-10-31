def multiply(F, M):
    x = F[0][0] * M[0][0] + F[0][1] * M[1][0]
    y = F[0][0] * M[0][1] + F[0][1] * M[1][1]
    z = F[1][0] * M[0][0] + F[1][1] * M[1][0]
    w = F[1][0] * M[0][1] + F[1][1] * M[1][1]
    F[0][0] = x
    F[0][1] = y
    F[1][0] = z
    F[1][1] = w


def power(F, n, m):
    if n <= 1:
        return
    M = [[1, 1], [1, 0]]
    power(F, n // 2, m)
    multiply(F, F)
    if n % 2 != 0:
        multiply(F, M)
        # gets the modulo of the matrix by modulo 2**m
    F[0][0] %= m
    F[0][1] %= m
    F[1][0] %= m
    F[1][1] %= m


def fib(n, m):
    if n <= 1:
        return n
    F = [[1, 1], [1, 0]]
    power(F, n - 1, m)
    return F[0][0]


while True:
    # asks for n and m and breaks when there is no more input
    try:
        n, m = map(int, input().split())
        print(fib(n, 2**m))

    except EOFError:
        break
