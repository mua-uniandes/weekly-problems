t = int(input())
for o in range(t):
	n,k = list(map(int,input().split()))
	a = list(map(int,input().split()))
	d = list(sorted(a))
	min1 = a.index(d[0])
	min2 = a.index(d[1])
	if min1 == min2:
		min2 += 1
	res1 = []
	if n > k or n == 2:
		print(-1)
	else:
		for i in range(n):
			if i+2 > n:
				res1.append(str(i+1)+' '+str(1))
			else:
				res1.append(str(i+1)+' '+str(i+2))
		res = 2*sum(a)
		while k > n:
			res1.append(str(min1 + 1)+' '+str(min2 + 1))
			res += d[0]+d[1]
			k -= 1
		print(res)
		for i in range(len(res1)):
			print(res1[i])