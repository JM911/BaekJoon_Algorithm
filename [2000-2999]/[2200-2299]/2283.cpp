// 2283. 구간 자르기
// G2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

#define MAX_NUM 1000010
int N, K;
int se[MAX_NUM];
int ps[MAX_NUM];

int main()
{
	FASTIO;

	cin >> N >> K;
	for(int i=0; i<N; i++)
	{
		int s, e;
		cin >> s >> e;
		se[s]++;
		se[e]--;

		// int len = e - s;
		// for(int j=1; j<=len; j++)
		// {
		// 	ps[s+j] += j;
		// }
		// for(int j=e+1; j<MAX_NUM; j++)
		// {
		// 	ps[j] += len;
		// }
	}

	int cur = 0;
	for(int i=0; i<MAX_NUM-1; i++)
	{
		cur += se[i];
		ps[i+1] = ps[i] + cur;
	}

	int s = 0;
	int e = 0;
	while(e < MAX_NUM)
	{

		int dist = ps[e] - ps[s];
		
		if(dist == K)
		{
			cout << s << ' ' << e;
			return 0;
		}
		if(dist < K)
			e++;
		if(dist > K)
			s++;
	}

	cout << 0 << ' ' << 0;
}