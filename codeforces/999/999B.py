s = input()
for i in range(2, n+1):
    if n % i == 0:
        s_revertir = s[:i]
        s_sobrante = s[i:]
        s = s_revertir[::-1] + s_sobrante
print(s)