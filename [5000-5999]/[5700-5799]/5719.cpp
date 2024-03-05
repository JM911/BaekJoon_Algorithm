// 5719. 거의 최단 경로
// P5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;
const int INF = 1e9;

int main()
{
	FASTIO;

	while(true)
	{
		int N, M, S, D;
		vector<vector<int>> adj;

		cin >> N >> M;
		adj.resize(N);
		for(auto& e : adj)
			e.resize(N, INF);

		if(N==0 && M==0) break;

		cin >> S >> D;

		while(M--)
		{
			int U, V, P;
			cin >> U >> V >> P;

			//adj[U].push_back({V, P});
			adj[U][V] = P;
		}

		vector<int> dist;
		vector<queue<int>> prevIdx;

		dist.resize(N, INF);
		prevIdx.resize(N);

		priority_queue<pii, vector<pii>, greater<pii>> pq;
		dist[S] = 0;
		pq.push({0, S});

		while(!pq.empty())
		{
			int curD = pq.top().first;
			int curV = pq.top().second;
			pq.pop();

			for(int i=0; i<N; i++)//auto e : adj[curV])
			{
				int nextD = curD + adj[curV][i];
				int nextV = i;

				if(nextD == dist[nextV])
				{
					prevIdx[nextV].push(curV);
				}
				else if(nextD < dist[nextV])
				{
					while(!prevIdx[nextV].empty())
						prevIdx[nextV].pop();
					prevIdx[nextV].push(curV);

					dist[nextV] = nextD;
					pq.push({nextD, nextV});
				}
			}
		}

		queue<int> q;
		q.push(D);
		while(!q.empty())
		{
			int curIdx = q.front();
			q.pop();

			while(!prevIdx[curIdx].empty())
			{
				int curPrevIdx = prevIdx[curIdx].front();
				prevIdx[curIdx].pop();

				adj[curPrevIdx][curIdx] = INF;
				q.push(curPrevIdx);
			}
		}


		dist.clear();
		dist.resize(N, INF);
		dist[S] = 0;
		pq.push({0, S});

		while(!pq.empty())
		{
			int curD = pq.top().first;
			int curV = pq.top().second;
			pq.pop();

			for(int i=0; i<N; i++)//auto e : adj[curV])
			{
				int nextD = curD + adj[curV][i];
				int nextV = i;

				if(nextD >= dist[nextV]) continue;

				dist[nextV] = nextD;
				pq.push({nextD, nextV});
			}
		}

		if(dist[D] >= INF)
			cout << -1 << '\n';
		else
			cout << dist[D] << '\n';
	}
}