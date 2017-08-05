#include <iostream>
#include <cstdio>

using namespace std;

#define INF 1000000007

int n, m, dp[30][30], a[30][30];

int main() {
	//freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);

	dp[1][1] = a[1][1];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (i == 1 && j == 1)
				continue;
			dp[i][j] = INF;
			if (j > 1)
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			if (i > 1)
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			dp[i][j] += a[i][j];
		}

	printf("%d", dp[n][m]);
}