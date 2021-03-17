def game(A):
    if sum(A)%2==0:
        print(1)
    else:
        print(2)
            
n = input()
n = int(n)

for i in range(n):
    a = input()
    z = input().split()
    A = list(map(int,z))
    game(A)