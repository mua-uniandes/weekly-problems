n=int(input())
for i in range (n):
    input()
    line=input().split(" ")
    par=0
    imp=0
    for num in line:
        if int(num)%2==0:
            par+=1
        else:
            imp+=1
    input()
    line = input().split(" ")
    par2 = 0
    imp2 = 0
    for num in line:
        if int(num) % 2 == 0:
            par2 += 1
        else:
            imp2 += 1
    print(par*par2+imp*imp2)