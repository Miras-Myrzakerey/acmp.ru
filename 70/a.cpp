#include <cstdio>
#include <iostream>
#include <string>
 
using namespace std;
 
string a;
int n,p[100001];
 
int main()
{   
    cin >> a >> n;
 
    if (n < 0)
    {
        int k = a.length () / -n;
        for (int i = 0; i < (int)a.length() - k; i += k)
        {
            if (a.substr(i,k) != a.substr(i + k,k))
            {
                puts ("NO SOLUTION");
                return 0;
            }
        }
        for (int i = 0; i < min(k, 1023); ++i)
        	putchar(a[i]);
    }
    else
    {
    	string ans = "";
    	for (int i = 1; i <= n; ++i) {
    		ans += a;
    		if (ans.length() >= 1023)
    			break;
    	}

    	for (int i = 0; i < min((int)ans.length(), 1023); ++i)
    		putchar(ans[i]);
    }
}