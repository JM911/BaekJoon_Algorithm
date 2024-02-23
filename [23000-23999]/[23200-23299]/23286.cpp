// 23286. 허들 넘기
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M, T;
int cost[310][310];

int main()
{
	FASTIO;

	cin >> N >> M >> T;
	fill(&cost[0][0], &cost[N][N+1], 0x3f3f3f3f);

	while(M--)
	{
		int u, v, h;
		cin >> u >> v >> h;
		cost[u][v] = h;
	}

	for(int i=1; i<=N; i++)
		for(int s=1; s<=N; s++)
			for(int e=1; e<=N; e++)
				cost[s][e] = min(cost[s][e], max(cost[s][i], cost[i][e]));

	while(T--)
	{
		int s, e;
		cin >> s >> e;
		cout << (cost[s][e]<0x3f3f3f3f ? cost[s][e] : -1) << '\n';
	}
}