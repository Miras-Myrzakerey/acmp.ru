#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 1100000

int n, a[MAXN], dp[MAXN][2];

int main() {
//	freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	dp[0][0] = 1;
	dp[0][1] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i][0] = 1;
		dp[i][1] = 1;
		if (a[i] < a[i - 1])
			dp[i][0] = dp[i - 1][1] + 1;
		if (a[i] > a[i - 1])
			dp[i][1] = dp[i - 1][0] + 1;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, max(dp[i][0], dp[i][1]));
	printf("%d", ans);
}