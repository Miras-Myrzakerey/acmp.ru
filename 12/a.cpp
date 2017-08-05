#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define eps 1e-8
int x[4], y[4], X, Y, n;

long long getCrossProduct(int x, int y, int x2, int y2) {
	return 1ll * x * y2 - 1ll * y * x2;
}

long long getTriangleArea(int x, int y, int x2, int y2, int x3, int y3) {
	return abs(getCrossProduct(x - x2, y - y2, x3 - x2, y3 - y2));	
}

double getDistance(int x, int y, int x2, int y2) {
	return sqrt((x - x2) * 1ll * (x - x2) + (y - y2) * 1ll * (y - y2));
}

int main() {
//	freopen("in", "r", stdin);
	scanf("%d", &n);

	int ans = 0;
	while (n--) {
		scanf("%d%d", &X, &Y);
		for (int i = 0; i < 4; ++i) {
			scanf("%d%d", &x[i], &y[i]);
		}

		long long totalArea = 0;
		for (int i = 0; i < 4; ++i) {
			totalArea += getTriangleArea(x[i], y[i], x[(i + 1) % 4], y[(i + 1) % 4], X, Y);			
		}

		if (totalArea - getDistance(x[0], y[0], x[1], y[1]) * getDistance(x[1], y[1], x[2], y[2]) * 2 < eps) {
			ans++;
		}
	}

	printf("%d", ans);
}                                  