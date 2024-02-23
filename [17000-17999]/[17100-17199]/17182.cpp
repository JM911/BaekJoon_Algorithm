// 17182. 우주 탐사선
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, K;
int T[11][11];

int ans = 0x7f7f7f7f;
int sum;
bool vis[11];

void Solve(int cur, int len)
{
	if(len == N)
	{
		ans = min(ans, sum);
		return;
	}
	
	for(int i=0; i<N; i++)
	{
		if(vis[i]) continue;

		vis[i] = true;
		sum += T[cur][i];
		Solve(i, len+1);
		sum -= T[cur][i];
		vis[i] = false;
	}
}

int main()
{
	FASTIO;

	cin >> N >> K;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> T[i][j];
		}
	}

	for(int i=0; i<N; i++)
	{
		for(int s=0; s<N; s++)
		{
			for(int e=0; e<N; e++)
			{
				if(T[s][i]+T[i][e] < T[s][e])
					T[s][e] = T[s][i] + T[i][e];
			}
		}
	}

	vis[K] = true;
	Solve(K, 1);
	cout << ans;
}