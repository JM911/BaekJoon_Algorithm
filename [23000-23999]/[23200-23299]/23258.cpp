// 23258. 밤편지
// P5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

#define MAX_SIZE 302

int N, Q;
int D[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int main()
{
	FASTIO;

	cin >> N >> Q;
	//fill(&D[0][0][0], &D[N+1][N+1][N+2], 180000);
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
		{
			cin >> D[0][i][j];
			if(D[0][i][j]==0 && i!=j)
				D[0][i][j] = 180000;
		}
		

	for(int i=1; i<=N; i++)
		for(int s=1; s<=N; s++)
			for(int e=1; e<=N; e++)
				D[i][s][e] = min(D[i-1][s][e], D[i-1][s][i] + D[i-1][i][e]);

	while(Q--)
	{
		int C, s, e;
		cin >> C >> s >> e;

		int ans = D[C-1][s][e];
		if(ans > 175000)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}
}