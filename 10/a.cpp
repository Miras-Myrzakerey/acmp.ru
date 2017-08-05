#include <cstdio>
#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);

	for (int x = -100; x <= 100; ++x) {
		if (1ll * a * x * x * x + 1ll * b * x * x + c * x + d == 0) {
			printf("%d ", x);
		}
	}

	puts("");
}