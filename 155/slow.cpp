#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
 
using namespace std;
 
#define eps 1e-7
 
int n, cnt, nSize, valSize, p[20], mark[20];
double c, a[20], ans[20], temp1, temp2, values[20];
double numbers[20], calc[2][20];
 
double connectPar(double x, double y) { //Parallel connection
    return x + y;
}
 
double connectSeq(double x, double y) { //Sequential connection
    return x * y / (x + y);
}
 
void getBlock(int l, int r) {
    temp1 = numbers[l];
    temp2 = numbers[l];
    for (int j = l + 1; j <= r; ++j) {
        temp1 = connectPar(temp1, numbers[j]);
        temp2 = connectSeq(temp2, numbers[j]);
    }                               
 
    calc[0][valSize] = temp1;
    calc[1][valSize] = temp2;
    valSize++;
}
 
int getBit(int givenMask, int bit) {
    return givenMask >> bit & 1;
}
 
void gen(int pos, double numbers[], int mark[]) {
	if (pos == n) {
		int start = 0;
		valSize = 0;
		for (int i = 0; i < nSize; ++i) {
			if (mark[i] == 1) {
				getBlock(start, i);
				start = i;
			}
		}

		if (start < nSize - 1) {
			getBlock(start, nSize);
		}

		for (int i = 0; i < valSize; ++i)
			p[i] = i;

		do {
			for (int firstMask = 0; firstMask < (1 << valSize); ++firstMask) {
				double value = -1;
				for (int opMask = 0; opMask < (1 << (valSize - 1)); ++opMask) {
					for (int i = 0; i < valSize; ++i)
						if (value + 1 < eps) {
							value = calc[getBit(firstMask, i)][p[i]];
						} else {
							if (getBit(opMask, i - 1)) {
								value = connectSeq(value, calc[getBit(firstMask, i)][p[i]]);								
							} else {
								value = connectPar(value, calc[getBit(firstMask, i)][p[i]]);
							}
						}

					if (abs(value - c) - 0.01 < eps) {
						puts("YES");
						exit(0);
					}
				}
			}
		} while(next_permutation(p, p + valSize));
	} else {
		gen(pos + 1, numbers, mark); //don't take a[pos]
		numbers[nSize] = a[pos];
		mark[nSize] = 0;
		nSize++;
		gen(pos + 1, numbers, mark); //take it, but don't end the group
		nSize--;
		mark[nSize] = 1;
		numbers[nSize] = a[pos];
		nSize++;
		gen(pos + 1, numbers, mark); //take it, end the group
		nSize--;
	}
}
 
int main() {
   	freopen("in", "r", stdin);
    scanf("%d%lf", &n, &c);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &a[i]);

    gen(0, numbers, mark);
 
    puts("NO");
}