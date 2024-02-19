// 1967. 트리의 지름
// G4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int n;
unordered_map<int, int> pd[10010];
unordered_set<int> c[10010];

int ans;

int MyFunc(int cur)
{
	if(c[cur].empty())
		return 0;
	
	int maxDist = 0;
	int secondDist = 0;

	for(auto e : c[cur])
	{
		int curDist = MyFunc(e) + pd[e][cur];
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

	if(c[cur].size() > 1)
		ans = max(ans, maxDist + secondDist);
	return maxDist;
}

int main()
{
	FASTIO;

	cin >> n;
	int cnt = n-1;
	while(cnt--)
	{
		int a, b, d;
		cin >> a >> b >> d;

		c[a].insert(b);
		pd[b].insert({a, d});
	}

	ans = max(ans, MyFunc(1));
	cout << ans;
}