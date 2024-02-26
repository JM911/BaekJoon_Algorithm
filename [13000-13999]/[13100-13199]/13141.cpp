// 13141. Ingition
// P5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M;
vector<vector<int>> edge;
//unordered_map<int, int> um;
vector<tuple<int, int, int>> v;

int main()
{
	FASTIO;

	cin >> N >> M;
	edge.resize(N+1);
	for(auto& e : edge)
		e.resize(N+1, 1e9);
	for(int i=1; i<=N; i++)
		edge[i][i] = 0;

	while(M--)
	{
		int S, E, L;
		cin >> S >> E >> L;
		
		edge[S][E] = min(edge[S][E], L);
		edge[E][S] = min(edge[E][S], L); //edge[S][E];
		
		// int h = S*1000 + E;
		// if(um.find(h) != um.end())
		// 	um[h] = max(um[h], L);
		// else
		// 	um.insert({h, L});

		v.push_back({S, E, L});
	}

	for(int i=1; i<=N; i++)
		for(int s=1; s<=N; s++)
			for(int e=1; e<=N; e++)
				edge[s][e] = min(edge[s][e], edge[s][i] + edge[i][e]);

	double ans = (double)1e9;
	for(int i=1; i<=N; i++)
	{
		double curAns = 0;
		for(auto e : v)
		{
			// int a = e.first / 1000;
			// int b = e.first % 1000;
			int a = get<0>(e);
			int b = get<1>(e);
			int l = get<2>(e);
			// int x = abs(edge[i][a] - edge[i][b]); //e.second);
			// curAns = max(curAns, (double)x + (double)max(l - x, 0) * 0.5 + (double)min(edge[i][a], edge[i][b]));

			int totalLen = edge[i][a] + edge[i][b] + l;
			curAns = max(curAns, (double)totalLen / 2);
		}
		ans = min(ans, curAns);
	}

	cout.precision(1);
	cout << fixed << ans;
}