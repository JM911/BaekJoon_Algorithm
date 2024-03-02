// 1854. K번째 최단경로 찾기
// P4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using tlii = tuple<ll, int, int>;

int n, m, k;
vector<vector<pil>> adj;
vector<list<ll>> dist;

int main()
{
	FASTIO;

	cin >> n >> m >> k;
	adj.resize(n+1);
	dist.resize(n+1);
	// for(auto& e : dist)
	// 	e.reserve(k);

	while(m--)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;

		adj[a].push_back({b, c});
	}

	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({0, 1});
	dist[1].push_back(0);

	while(!pq.empty())
	{
		int curD = pq.top().first;
		int curV = pq.top().second;
		pq.pop();

		for(auto e : adj[curV])
		{
			int nextD = curD + e.second;
			int nextV = e.first;

			if(dist[nextV].size() >= k && nextD >= dist[nextV].back()) continue;
			
			dist[nextV].push_back(nextD);
			// sort(dist[nextV].begin(), dist[nextV].end());
			dist[nextV].sort();

			if(dist[nextV].size() > k)
				dist[nextV].pop_back();

			pq.push({nextD, nextV});
		}
	}

	for(int i=1; i<=n; i++)
	{
		auto e = dist[i];
		if(e.size() < k)
			cout << -1 << '\n'; 
		else
		{
			// sort(e.begin(), e.end());
			cout << e.back() << '\n';
		}
	}
}