// 1068. 트리
// G5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;
int p[55];
unordered_set<int> c[55];
bool vis[55];
int rt, ans;

void DFS(int cur)
{
	if(vis[cur]) return;
	vis[cur] = true;
	
	if(c[cur].empty())
		ans++;

	for(auto e : c[cur])
	{
		DFS(e);
	}
}

int main()
{
	FASTIO;

	cin >> N;
	for(int i=0; i<N; i++)
	{
		int curP;
		cin >> curP;
		p[i] = curP;

		if(curP < 0)
			rt = i;
		else
			c[curP].insert(i);
	}

	int cutNode;
	cin >> cutNode;

	if(cutNode != rt)
	{
		int cutP = p[cutNode];
		c[cutP].erase(cutNode);
		DFS(rt);
	}
	cout << ans;
}