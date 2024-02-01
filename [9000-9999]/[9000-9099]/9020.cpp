// 9020. 골드바흐의 추측
// S2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int T;
vector<bool> p;

int main()
{
	FASTIO;

	const int MAX_NUM = 10010;
	p.resize(MAX_NUM+10, true);

	p[0] = false;
	p[1] = false;
	for(int i=2; i*i <= MAX_NUM; i++)
	{
		if(!p[i]) continue;
		for(int j=2; i*j<=MAX_NUM; j++)
		{
			p[i*j] = false;
		}
	}

	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;

		int halfN = n/2;
		for(int i=halfN; i<=n; i++)
		{
			if(p[i] && p[n-i])
			{
				cout << n-i << ' ' << i << '\n';
				break;
			}
		}
	}
}