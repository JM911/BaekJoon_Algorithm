// 1439. 뒤집기
// S5

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

string S;
int ans;

int main()
{
	setIO("");

    cin >> S;

    int len = S.length();
    for(int i=0; i<len-1; i++)
    {
        if(S[i+1] != S[i])  ans++;
    }

    ans++;
    ans /= 2;

    cout << ans;
}