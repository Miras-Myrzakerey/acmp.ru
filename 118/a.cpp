#include <cstdio>
#include <iostream>

using namespace std;

int n, k, ans[600];

int main() {
	scanf("%d%d", &n, &k);
	ans[1] = 1;
	for (int i = 2; i <= n; ++i)
		ans[i] = 1 + (ans[i - 1] + k - 1) % i;
	printf("%d", ans[n]);
}