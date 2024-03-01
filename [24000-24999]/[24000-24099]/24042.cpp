// 24042. 횡단보도
// G1

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int N, M;

const ll INF = 1e13;
vector<vector<pair<int, ll>>> adj;
vector<ll> ans;

int main()
{
	FASTIO;

	cin >> N >> M;
	adj.resize(N+1);
	ans.resize(N+1, INF);

	for(int i=0; i<M; i++)
	{
		int A, B;
		cin >> A >> B;
		adj[A].push_back({B, i});
		adj[B].push_back({A, i});
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, 1});
	ans[1] = 0;

	while(!pq.empty())
	{
		ll curD = pq.top().first;
		int curV = pq.top().second;
		pq.pop();

		if(curD != ans[curV]) continue;

		for(auto e : adj[curV])
		{
			int nextV = e.first;
			ll nextD = (curD / M) * M + e.second;
			while(nextD < curD)
				nextD += M;
			
			if(nextD+1 >= ans[nextV]) continue;
			
			ans[nextV] = nextD + 1;
			pq.push({nextD+1, nextV});
		}
	}

	cout << ans[N];
}