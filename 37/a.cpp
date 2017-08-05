#include <cstdio>
#include <cmath>
#include <iostream>
 
using namespace std;

#define eps 1e-7

int n;
long long x, y, x2, y2, q2;
double q;
 
int main()
{
	freopen("in", "r", stdin);
    scanf ("%d%lf", &n, &q);
    q2 = (long long)(q * 1000 + 0.5);
    cerr << q2;

    while (n--) {
    	scanf("%I64d%I64d%I64d%I64d", &x, &y, &x2, &y2);

    	if (1000000ll * (x2 * x2 + y2 * y2) > q2 * q2 * (x * x + y * y)) {
    		puts("No");
    		return 0;
    	}
    }
 
    puts ("Yes");
}