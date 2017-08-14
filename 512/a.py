n, m, k = map(int, input().split())
a = []
d = [0] * (1 << n)
d2 = d[:]
d[0] = 1
ans = 0

for i in range(n):
	a.append(input())

for i in range(m):
	for j in range(1 << n):
		d2[j] += d[j]
		for s in range(n):
			if (a[s][i] == 'Y' and not (j >> s & 1)):
				d2[j | (1 << s)] += d[j]
		d[j] = 0
		if (i == m - 1 and bin(j).count('1') == k):
			ans += d2[j]
	d, d2 = d2, d
print(ans)
