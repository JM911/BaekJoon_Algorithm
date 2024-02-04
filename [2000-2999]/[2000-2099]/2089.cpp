// 2089. -2진수
// S2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
ll N;

int main()
{
	FASTIO;

	cin >> N;
	
	int cnt = 1;
	ll add = 2;
	while(true)
	{
		N += add;
		if(N>=0 && N<add*2) 
			break;
		
		add *= 4;
		cnt++;
	}

	string ans = "";
	add /= 2;

	while(cnt--)
	{
		ll token = N / add;
		switch(token)
		{
		case 0:
			ans += "10";
			break;
		case 1:
			ans += "11";
			break;
		case 2:
			ans += "00";
			break;
		case 3:
			ans += "01";
			break;
		}

		N %= add;
		add /= 4;
	}

	int len = ans.length();
	for(int i=0; i<len; i++)
	{
		if(i==0 && ans[i] == '0') continue;
		cout << ans[i];
	}
}