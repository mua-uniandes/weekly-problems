class ShorterSuperSum:
    def __init__(self):
        self.m={}
    def calculate(self,k,n):
        if k==0:
            return n
        if str(k)+"|"+str(n) in self.m:
            return self.m[str(k)+"|"+str(n)]
        s=0
        for i in range(1,n+1):
            s+=self.calculate(k-1,i)
        self.m[str(k)+ "|"+ str(n)]=s
        return s