// 17103. 골드바흐 파티션
// S2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int T;
vector<bool> p;

int main()
{
	FASTIO;

	const int MAX_NUM = 1000000;
	p.resize(MAX_NUM+10, true);

	p[0] = false;
	p[1] = false;
	for(int i=2; i*i < MAX_NUM; i++)
	{
		if(!p[i]) continue;
		int mult = 2;
		while(true)
		{
			int curNum = i*mult;
			if(curNum > MAX_NUM) break;

			p[curNum] = false;
			mult++;
		}
	}

	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		
		int halfN = N/2;
		int ans = 0;
		for(int i=2; i<=halfN; i++)
		{
			if(p[i] && p[N-i]) ans++;
		}

		cout << ans << '\n';
	}
}