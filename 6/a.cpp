#include <cstdio>
#include <iostream>

using namespace std;

char s[5];

bool isAlpha(char c) {
	return c >= 'A' && c <= 'H';	
}

bool isDigit(char c) {
	return c >= '1' && c <= '8';
}

int abs(char x) {
	return x >= 0 ? x : -x;	
}

int main() {
	gets(s);
	
	if (!isAlpha(s[0]) || !isAlpha(s[3]) || s[2] != '-' || !isDigit(s[1]) || !isDigit(s[4])) {
		puts("ERROR");
		return 0;		
	}

	int charDiff = abs(s[0] - s[3]);
	int digDiff = abs(s[1] - s[4]);
	if (charDiff > 2 || digDiff > 2 || charDiff + digDiff != 3) {
		puts("NO");
	} else {
		puts("YES");
	}
}