#include <cstdio>
#include <iostream>

using namespace std;

#define mod 1000000007

int n, a[40000];

int main() {
//	freopen("in", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int len = 1; len <= n; ++len) {
		if ((n - 1) % len == 0) {
			bool ok = true;
			for (int start = 0; start + len < n; start += len) {				
				for (int i = start; i < start + len; ++i)
					if (a[i] != a[i - start]) {
						ok = false;
						break;
					}				
			}

			if (ok) {
				printf("%d\n", len);
				return 0;
			}
		}
	}
}