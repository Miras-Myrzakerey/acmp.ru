#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
 
using namespace std;
 
#define eps 1e-7
 
int n, cnt, nSize, valSize, p[20];
double c, a[20], ans[20], temp1, temp2, values[20], calc[2][20];
double numbers[20], parValues[20], seqValues[20], mark[20], temp[20];
 
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
 
void gen(int l) {
    if (l == nSize) {
        int start = 0;
        valSize = 0;
 
        for (int i = 0; i < nSize; ++i) {
            if (mark[i] == 1) {
                getBlock(start, i);
                start = i + 1;              
            }
        }
 
        if (start < nSize) {
            getBlock(start, nSize - 1);
        }

        for (int j = 0; j < 2; ++j) {
        	double value = calc[j][0];
        	for (int i = 1; i < valSize; ++i) {
        		if (!j) {
	        		value = connectSeq(value, calc[j][i]);
	        	} else {
	        		value = connectPar(value, calc[j][i]);
	        	}
			}

            if (abs(value - c) - 0.01 < eps) {
            	puts("YES");
            	exit(0);
            }
        }
    } else {
        mark[l] = 0;
        gen(l + 1);
        mark[l] = 1;
        gen(l + 1);
    }
}
 
int main() {
    freopen("in", "r", stdin);
    scanf("%d%lf", &n, &c);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &a[i]);
 
    for (int myMask = 0; myMask < (1 << n); ++myMask) {
        nSize = 0;
        for (int i = 0; i < n; ++i)
            if (myMask >> i & 1) {
                temp[nSize] = a[i];
                p[i] = i;
                nSize++;
            }
 
        do {
            for (int i = 0; i < nSize; ++i)
                numbers[i] = temp[p[i]];
            gen(0);
        } while (next_permutation(p, p + nSize));
    }
 
    puts("NO");
}