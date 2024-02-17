// 1325. 효율적인 해킹
// S1

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M;
vector<vector<int>> adj;

int main()
{
	FASTIO;

	cin >> N >> M;
	adj.resize(N+1);

	while(M--)
	{
		int a, b;
		cin >> a >> b;

		adj[b].push_back(a);
	}

	vector<int> ans;
	int maxVal = 0;

	for(int i=1; i<=N; i++)
	{
		vector<bool> vis;
		vis.resize(N+1, false);

		queue<int> q;
		vis[i] = true;
		int curVal = 1;
		q.push(i);

		while(!q.empty())
		{
			int cur = q.front();
			q.pop();

			for(auto e : adj[cur])
			{
				if(vis[e]) continue;
				vis[e] = true;
				curVal++;
				q.push(e);
			}
		}

		if(curVal > maxVal)
		{
			maxVal = curVal;
			ans.clear();
		}
		if(curVal == maxVal)
		{
			ans.push_back(i);
		}
	}

	for(auto e : ans)
	{
		cout << e << ' ';
	}
}