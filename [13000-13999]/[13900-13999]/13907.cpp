// 13907. 세금
// P4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 2e9;

int N, M, K, S, D;
vector<vector<pii>> adj;
vector<pii> dist;
vector<vector<int>> distPath; // dist[a][b] 는 시작 -> a 로 가는 경로 중 b 개의 경로를 가진 것의 최소 거리 값

int main()
{
	FASTIO;

	cin >> N >> M >> K >> S >> D;
	adj.resize(N+1);

	while(M--)
	{
		int a, b, w;
		cin >> a >> b >> w;

		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	dist.resize(N+1, {INF, INF});
	priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
	dist[S] = {0, 0};
	pq.push({0, S, 0});

	while(!pq.empty())
	{
		int curD, curV, curL;
		tie(curD, curV, curL) = pq.top();
		pq.pop();

		for(auto e : adj[curV])
		{
			int nextD = curD + e.second;
			int nextV = e.first;
			int nextL = curL + 1;

			if(nextD >= dist[nextV].first) continue;

			dist[nextV] = {nextD, nextL};
			pq.push({nextD, nextV, nextL});
		}
	}

	int maxL = dist[D].second;

	distPath.resize(N+1);
	for(auto& e : distPath)
		e.resize(N+1, INF);
	distPath[S][0] = 0;
	distPath[D][maxL] = dist[D].first;
	pq.push({0, S, 0});

	while(!pq.empty())
	{
		int curD, curV, curL;
		tie(curD, curV, curL) = pq.top();
		pq.pop();

		for(auto e : adj[curV])
		{
			int nextD = curD + e.second;
			int nextV = e.first;
			int nextL = curL + 1;

			if(nextL >= maxL || nextD >= distPath[nextV][nextL]) continue;

			distPath[nextV][nextL] = nextD;
			pq.push({nextD, nextV, nextL});
		}
	}

	int totalTax = 0;

	cout << dist[D].first << '\n';

	while(K--)
	{
		int p;
		cin >> p;
		totalTax += p;

		int ans = INF;
		for(int i=0; i<=maxL; i++)
		{
			if(distPath[D][i] >= INF) continue;
			ans = min(ans, distPath[D][i] + i * totalTax);
		}

		cout << ans << '\n';
	}
}