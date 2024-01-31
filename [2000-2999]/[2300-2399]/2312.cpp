// 2312. 수 복원하기
// S3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int T;
vector<bool> p;
vector<int> pV;

int main()
{
	FASTIO;

	const int MAX_NUM = 100000;
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
	
	for(int i=2; i<=MAX_NUM; i++)
	{
		if(p[i]) pV.push_back(i);
	}

	cin >> T;
	
	while(T--)
	{
		int N;
		cin >> N;

		int curNum = N;
		for(auto a : pV)
		{
			if(a > N) break;

			int cnt = 0;
			while(curNum%a == 0)
			{
				cnt++;
				curNum /= a;
			}
			if(cnt > 0)
			{
				
				cout << a << ' ' << cnt << '\n';
			}
		}
	}
}