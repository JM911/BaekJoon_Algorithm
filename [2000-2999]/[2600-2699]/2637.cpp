// 2637. 장난감 조립
// G2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M;
int d[105][105];
vector<vector<pair<int, int>>> XYK;
vector<unordered_set<int>> YX;
vector<int> ind;
vector<int> basePart;

int main()
{
	FASTIO;

	cin >> N >> M;
	XYK.resize(N+1);
	YX.resize(N+1);
	ind.resize(N+1, 0);

	while(M--)
	{
		int X, Y, K;
		cin >> X >> Y >> K;

		XYK[X].push_back({Y, K});
		YX[Y].insert(X);
		ind[X]++;
	}

	queue<int> q;
	for(int i=1; i<=N; i++)
	{
		if(ind[i] == 0)
		{
			basePart.push_back(i);
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		if(XYK[cur].empty())
			d[cur][cur] = 1;
		else
		{
			for(auto e : XYK[cur])
			{
				for(auto e2 : basePart)
				{
					d[cur][e2] += d[e.first][e2] * e.second;
				}
			}
		}

		for(auto e : YX[cur])
		{
			ind[e]--;
			if(ind[e] == 0)
				q.push(e);
		}
	}

	for(auto e : basePart)
	{
		cout << e << ' ' << d[N][e] << '\n';
	}
}