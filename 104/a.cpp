#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

char a[300], b[300];
bool dp[300][300];

bool isAlpha(char c) {
	return c >= 'A' && c <= 'Z';
}

int main() {
	freopen("in", "r", stdin);
	scanf("%s", a);
	scanf("%s", b);
	dp[0][0] = 1;
	int n = strlen(a);
	int m = strlen(b);
	for (int i = 0; i < n; ++i)
		if (a[i] == '*' || a[i] == '?') {
			swap(a, b);
			swap(n, m);
			break;
		}

	for (int j = 0; j < m; ++j)
		if (b[j] != '*') {
			break;
		} else {
			dp[0][j + 1] = 1;
		}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j];
				if (b[j] == '*')
					dp[i][j + 1] |= dp[i][j + 1] | dp[i + 1][j];
			} else {
				if (isAlpha(b[j])) {
					dp[i + 1][j + 1] = 0;
				} else {	
					dp[i + 1][j + 1] |= dp[i][j]; 
					if (b[j] == '*') {
						dp[i + 1][j + 1] |= dp[i + 1][j]; //empty star
						dp[i + 1][j + 1] |= dp[i][j + 1]; //continue star
					}
				}
			}
		}			
	}

	puts(dp[n][m] ? "YES" : "NO");
}