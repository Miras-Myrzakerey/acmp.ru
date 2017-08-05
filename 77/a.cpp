#include <cstdio>
#include <iostream>

using namespace std;

int n, k, rep[33];
long long c[33][33];

int main() {
	scanf("%d%d", &n, &k);

	int len = 0;
	while ((1 << len) <= n) ++len;
	for (int i = 0; i < len; ++i) {
		rep[len - i - 1] = n >> i & 1;
	}		

	c[0][0] = 1;
	for (int i = 1; i < 33; ++i) {
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}

	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < len; ++i) {
		if (len - i >= k - cnt && k - cnt >= 0)
			ans += c[len - i - 1][k - cnt];
		if (rep[i] == 0) {
			cnt++;
		}
	}

	cout << ans;
}