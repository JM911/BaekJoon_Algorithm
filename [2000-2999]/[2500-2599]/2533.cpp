// 2533. 사회망 서비스(SNS)
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;

vector<int> adj[1000010];
int p[1000010];
unordered_set<int> c[1000010];

vector<bool> vis;
queue<int> leaf;

int main()
{
	FASTIO;

	cin >> N;
	vis.resize(N+1, false);

	int cnt = N-1;
	while(cnt--)
	{
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int rt = 1;
	p[rt] = -1;
	queue<int> q;
	q.push(rt);

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for(auto e : adj[cur])
		{
			if(e == p[cur]) continue;

			c[cur].insert(e);
			p[e] = cur;
			q.push(e);
		}

		if(c[cur].empty())
			leaf.push(cur);
	}

	int ans = 0;
	while(!leaf.empty())
	{
		int cur = leaf.front();
		leaf.pop();
		int curP = p[cur];

		if(curP < 0) continue;
		if(vis[curP]) continue;

		ans++;
		vis[curP] = true;

		int curPP = p[curP];

		if(curPP < 0) continue;

		c[curPP].erase(curP);
		if(c[curPP].empty())
			leaf.push(curPP);
	}

	cout << ans;
}