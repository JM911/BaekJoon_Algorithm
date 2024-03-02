// 1162. 도로포장
// P5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using pii = pair<int, ll>;
using tiii = tuple<ll, int, int>;
int N, M, K;

const ll INF = (ll)1e13;
vector<vector<pii>> adj;
vector<vector<ll>> dist;

struct MyComp
{
	bool operator()(const tiii& a, const tiii& b)
	{
		return get<0>(a) > get<0>(b);
	}
};

int main()
{
	FASTIO;

	cin >> N >> M >> K;
	adj.resize(N+1);
	dist.resize(N+1);
	for(auto& e : dist)
		e.resize(K+1, INF);

	while(M--)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;

		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	priority_queue<tiii, vector<tiii>, MyComp> pq;
	// queue<tiii> pq;
	pq.push({0, 1, 0});
	dist[1][0] = 0;

	while(!pq.empty())
	{
		ll curD;
		int curV, curK;
		tie(curD, curV, curK) = pq.top();
		pq.pop();

		if(curD > dist[curV][curK]) continue;
		
		for(auto e : adj[curV])
		{
			ll nextD = curD + e.second;
			int nextV = e.first;

			if(nextD < dist[nextV][curK])
			{
				dist[nextV][curK] = nextD;
				pq.push({nextD, nextV, curK});
			}
			if(curK<K && curD < dist[nextV][curK+1])
			{
				dist[nextV][curK+1] = curD;
				pq.push({curD, nextV, curK+1});
			}
		}
	}

	ll ans = dist[N][0];
	for(int i=1; i<=K; i++)
		ans = min(ans, dist[N][i]);
	cout << ans;
}