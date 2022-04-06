n,k=map(int,input().split())
st=input()

def solve(n, k, st):
    num=[0]*n
    ret=""
    for i in range(n):
        num[i]+=ord(st[i])-96
    max_summa=n*26
    suma=sum(num)
    if k/n<=25:
        for i in range(n):
            raz=26-num[i]
            if raz>=13:
                if raz<=k:
                    ret+="z"
                    k-=raz
                else:
                    ret += chr(96+k+num[i])+st[i+1:]
                    k=0
                    break
            else:
                if (num[i]-1) <= k:
                    ret += "a"
                    k -= num[i]-1
                else:
                    ret += chr(96 + num[i]-k) + st[i + 1:]
                    k=0
                    break
        if k==0: 
            return ret
        else: 
            return -1
    else:
        return -1

print(solve(n, k, st))