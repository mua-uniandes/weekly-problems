a,b = input().split()
a = int(a)
b = int(b)
z= input().split()
z = list(map(int,z))
def frog(b,z):
    y=[]
    y.append(0)
    for i in range(a-1):
        y.append(float('inf'))
    for i in range(a):
        for j in range(i+1,min(a,i+b+1)):
            y[j] =min(y[j],y[i]+abs(z[i]-z[j]))
    return y[-1]
print(frog(b,z))