// 1916. 최소비용 구하기
// G5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;
int N, M;

const int INF = 1e9;
vector<vector<pair<int, int>>> adj;
vector<int> ans;

int main()
{
	FASTIO;

	cin >> N >> M;
	adj.resize(N+1);
	ans.resize(N+1, INF);

	while(M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

	int S, E;
	cin >> S >> E;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, S});

	while(!pq.empty())
	{
		int curD = pq.top().first;
		int curV = pq.top().second;
		pq.pop();

		if(curD >= ans[curV]) continue;
		ans[curV] = curD;

		for(auto e : adj[curV])
		{
			int nextD = curD + e.second;
			int nextV = e.first;
			
			if(nextD >= ans[nextV]) continue;

			pq.push({nextD, nextV});
		}
	}

	cout << ans[E];
}