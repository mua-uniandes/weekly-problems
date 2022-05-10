class BadNeighbors:
    def __init__(self):
        pass

    def maxDonations(self, a):
        self.a = a
        self.m = [[0 for _ in enumerate(a)],[0 for _ in enumerate(a)]]
        return self.n(0,len(a)-1)

    def n(self, j,i):
        if i < j: 
            return 0
        elif self.m[j][i]: return self.m[j][i]
        elif i == j:
            result = self.a[i]
            self.m[j][i] = result
            return result
        elif i == j+1:
            result = max(self.a[i], self.a[j])
            self.m[j][i] = result
            return result
        elif i == len(self.a)-1:
            result = max(self.a[i]+self.n(1,i-2), self.n(0,i-1))
            self.m[j][i] = result
            return result
        else:
            result = max(self.a[i]+self.n(j,i-2), self.n(j, i-1))
            self.m[j][i] = result
            return result
