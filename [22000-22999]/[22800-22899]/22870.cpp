// 22870. 산책 (large)
// P4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;
const int INF = 2e9;

int N, M, S, E;
vector<vector<pii>> adj;
vector<int> dist;

vector<int> minPath;
vector<bool> visited;
int ans;

int main()
{
	FASTIO;
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);

	cin >> N >> M;
	adj.resize(N+1);

	while(M--)
	{
		int A, B, C;
		cin >> A >> B >> C;

		adj[A].push_back({B, C});
		adj[B].push_back({A, C});
	}

	for(auto& e : adj)
		sort(e.begin(), e.end());

	cin >> S >> E;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	dist.resize(N+1, INF);

	dist[E] = 0;
	pq.push({0, E});

	while(!pq.empty())
	{
		auto [curD, curV] = pq.top();
		pq.pop();

		for(auto e : adj[curV])
		{
			int nextD = curD + e.second;
			int nextV = e.first;

			if(nextD >= dist[nextV]) continue;

			dist[nextV] = nextD;
			pq.push({nextD, nextV});
		}
	}

	ans += dist[S];

	visited.resize(N+1, false);
	int curIdx = S;
	int totalD = 0;
	while(curIdx != E)
	{
		for(auto e : adj[curIdx])
		{
			int nextV = e.first;
			int nextD = e.second;

			if(totalD + nextD + dist[nextV] == dist[S])
			{
				visited[nextV] = true;
				totalD += nextD;
				curIdx = nextV;
				break;
			}
		}
	}
	

	dist.clear();
	dist.resize(N+1, INF);

	dist[E] = 0;
	pq.push({0, E});

	while(!pq.empty())
	{
		auto [curD, curV] = pq.top();
		pq.pop();

		for(auto e : adj[curV])
		{
			int nextD = curD + e.second;
			int nextV = e.first;

			if(visited[nextV] || nextD>=dist[nextV]) continue;

			dist[nextV] = nextD;
			pq.push({nextD, nextV});
		}
	}

	ans += dist[S];

	cout << ans;
}