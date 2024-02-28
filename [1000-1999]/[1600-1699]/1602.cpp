// 1602. 도망자 원숭이
// P3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M, Q;
vector<int> dog;
vector<vector<int>> dist;

int main()
{
	FASTIO;

	cin >> N >> M >> Q;
	dog.resize(N+1);
	for(int i=1; i<=N; i++)
		cin >> dog[i];
	
	dist.resize(N+1);
	for(auto& e : dist)
		e.resize(N+1, 1000001);
	for(int i=1; i<=N; i++)
		dist[i][i] = 0;
	
	while(M--)
	{
		int a, b, d;
		cin >> a >> b >> d;

		dist[a][b] = d;
		dist[b][a] = d;
	}

	vector<vector<int>> curDog;
	curDog.resize(N+1);
	for(auto& e : curDog)
		e.resize(N+1, 0);

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			curDog[i][j] = max(dog[i], dog[j]);
	
	queue<int> q;
	for(int i=1; i<=N; i++)
		q.push(i);
	vector<bool> vis;
	vis.resize(N+1, false);

	while(!q.empty())
	{
		int i = q.front();
		q.pop();

		if(vis[i]) continue;
		vis[i] = true;

		for(int s=1; s<=N; s++)
			for(int e=1; e<=N; e++)
			{
				int newDog = max(curDog[s][i], curDog[i][e]);
				if(dist[s][e]+curDog[s][e] > dist[s][i]+dist[i][e]+newDog)
				{
					dist[s][e] = dist[s][i]+dist[i][e];
					curDog[s][e] = newDog;

					if(vis[s])
					{
						q.push(s);
						vis[s] = false;
					}
					if(vis[e])
					{
						q.push(e);
						vis[e] = false;
					}
				}
			}
	}

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(dist[i][j] > 1000000)
			{
				dist[i][j] = -1;
				curDog[i][j] = 0;
			}

	while(Q--)
	{
		int S, T;
		cin >> S >> T;

		cout << dist[S][T] + curDog[S][T] << '\n';
	}
}