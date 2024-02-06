for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    i = 0
    found = False
    for i in range(n-1):
        if a[i] == 0 and a[i+1]==1:
            found = True
            break
    if found:
        print(*range(1, i+2), n+1, *range(i+2, n+1), sep=' ')
    elif a[-1] == 0:
        print(*range(1, n+2), sep=' ')
    elif a[0] == 1:
        print(n+1, *range(1, n+1), sep=' ')
    else:
        print(-1)

      	  				  		   	 			 				