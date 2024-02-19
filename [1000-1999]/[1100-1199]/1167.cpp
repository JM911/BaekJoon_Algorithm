// 1167. 트리의 지름
// G2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int V;
unordered_map<int, int> adjd[100010];
//unordered_set<int> c[100010];

ll ans;

ll MyFunc(int cur, int par)
{
	if(par>0 && adjd[cur].size() <= 1)
		return 0;
	
	ll maxDist = 0;
	ll secondDist = 0;

	for(auto e : adjd[cur])
	{
		if(e.first == par) continue;

		ll curDist = MyFunc(e.first, cur) + e.second;
		if(curDist > maxDist)
		{
			secondDist = maxDist;
			maxDist = curDist;
		}
		else if(curDist > secondDist)
		{
			secondDist = curDist;
		}
	}

	if(adjd[cur].size() > (par > 0 ? 2 : 1))
		ans = max(ans, maxDist + secondDist);
	return maxDist;
}

int main()
{
	FASTIO;

	cin >> V;
	while(V--)
	{
		int a;
		cin >> a;

		while(true)
		{
			int b, d;
			cin >> b;

			if(b == -1) break;

			cin >> d;

			adjd[a].insert({b, d});
			//adjd[b].insert({a, d});
		}
	}

	ans = max(ans, MyFunc(1, 0));
	cout << ans;
}