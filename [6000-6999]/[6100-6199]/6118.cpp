// 6118. 숨바꼭질
// S1

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> dist;
int ansIdx, ansDist, ansNum;

int main()
{
	FASTIO;

	cin >> N >> M;
	adj.resize(N+1);
	dist.resize(N+1, -1);

	while(M--)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	
	dist[1] = 0;
	q.push(1);

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for(auto e : adj[cur])
		{
			if(dist[e] >= 0) continue;
			dist[e] = dist[cur] + 1;
			q.push(e);

			if(dist[e] == ansDist)
			{
				ansIdx = min(ansIdx, e);
				ansNum++;
			}
			else if(dist[e] > ansDist)
			{
				ansDist = dist[e];
				ansIdx = e;
				ansNum = 1;
			}
		}
	}

	cout << ansIdx << ' ' << ansDist << ' ' << ansNum;
}