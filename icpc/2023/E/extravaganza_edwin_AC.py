from sys import stdin

tcnt = int(stdin.readline())
while tcnt!=0:
    S = stdin.readline().split()[1]
    opn, sol = 0, 0
    for c in S:
        if c=='(': opn+=1
        elif opn>0: 
            opn-=1
            sol+=2
    print(sol)
    tcnt -= 1
