q = int(input())
for i in range(q):
	s = input()
	t = input()
	n = len(s)
	m = len(t)
	ans = False
	for i in range(n):
		for j in range(0, n - i):
			k = m - 1 - j
			if i + j < k:
				continue                                 
			l1 = i
			r = i + j
			l2 = r - k                                
			if s[l1:r+1] + s[l2:r][::-1] == t:
				ans = True	
	print('YES' if ans else 'NO')