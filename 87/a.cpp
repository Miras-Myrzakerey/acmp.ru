#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#define mod 1000000007

string s[250];
int mHash[250];
map<int, int> mp;

int modPow(int x, int p) {
	int res = 1;
	while (p > 0) {
		if (p & 1)
			res = res * 1ll * x % mod;
		p >>= 1;
		x = x * 1ll * x % mod;							
	}

	return res;
}

int main() {
	freopen("in", "r", stdin);
	int n = 0;
	while (true) {
		cin >> s[n];
		if (s[n] == "ENDOFINPUT")
			break;
		for (int j = 0; j < (int)s[n].length(); ++j)
			mHash[n] = (mHash[n] * 37ll + s[n][j]) % mod;
		mp[mHash[n]]++;
		n++;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int mainHash = mHash[i];
		for (int j = 0; j < n; ++j) {
			if (s[j].length() < s[i].length()) {
				int tempHash = (mainHash - mHash[j] * 1ll * modPow(37, (int)s[i].length() - (int)s[j].length()) % mod + mod) % mod;  
				if (mp[tempHash]) {
					ans++;
					break;
				}
			}
		}
	}

	printf("%d", ans);
}