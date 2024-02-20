// 2056. 작업
// G4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;
vector<int> T;
vector<vector<int>> adj;
vector<int> ind;

int main()
{
	FASTIO;

	cin >> N;
	T.resize(N+1);
	adj.resize(N+1);
	ind.resize(N+1, 0);

	unordered_map<int, int> um;
	for(int i=1; i<=N; i++)
	{
		cin >> T[i] >> ind[i];

		int cnt = ind[i];
		while(cnt--)
		{
			int tmp;
			cin >> tmp;
			adj[tmp].push_back(i);
		}

		if(ind[i] <= 0)
		{
			um.insert({i, T[i]});
			ind[i]--;
		}
	}

	// for(int i=1; i<=N; i++)
	// {
	// 	if(ind[i] == 0)
	// 	{
	// 		um.insert({i, T[i]});
	// 		ind[i]--;
	// 	}
	// }

	int ans = 0;
	while(!um.empty())
	{
		unordered_set<int> eraseList;
		unordered_set<int> insertList;
		int timeSpend = 101;

		for(auto e : um)
		{
			timeSpend = min(timeSpend, e.second);
		}

		for(auto& e : um)
		{
			e.second -= timeSpend;
			if(e.second <= 0)
			{
				eraseList.insert(e.first);
				for(auto e2 : adj[e.first])
				{
					ind[e2]--;
					if(ind[e2] <= 0)
					{
						insertList.insert(e2);
						ind[e2]--;
					}
				}
			}
		}
		ans += timeSpend;

		for(auto e : eraseList)
			um.erase(e);

		for(auto e : insertList)
			um.insert({e, T[e]});
	}

	cout << ans;
}
