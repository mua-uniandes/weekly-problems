n, k = [int(x) for x in input().split()]
l = [int(x) for x in input().split()]
 
s = sum(l[0:k])
t = s
ind=1
for i in range(k, n):
	t -=l[i-k]
	t +=l[i]
	if t<s:
		s = t
		ind = i-k+2
print(ind)