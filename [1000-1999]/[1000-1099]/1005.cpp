// 1005. ACM craft
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int T, N, K, W;
vector<int> D;
vector<vector<int>> XY;
vector<vector<int>> YX;
vector<int> ind;
vector<int> dp;

int main()
{
	FASTIO;

	cin >> T;
	while(T--)
	{
		D.clear();
		XY.clear();
		YX.clear();
		ind.clear();
		dp.clear();

		cin >> N >> K;
		D.resize(N+1);
		XY.resize(N+1);
		YX.resize(N+1);
		ind.resize(N+1, 0);
		dp.resize(N+1, 0);

		for(int i=1; i<=N; i++)
			cin >> D[i];
		
		while(K--)
		{
			int X, Y;
			cin >> X >> Y;
			XY[X].push_back(Y);
			YX[Y].push_back(X);
			ind[Y]++;
		}

		cin >> W;

		queue<int> q;

		for(int i=1; i<=N; i++)
		{
			if(ind[i] == 0)
				q.push(i);
		}

		while(!q.empty())
		{
			int cur = q.front();
			q.pop();

			int curDelay = D[cur];
			int addDelay = 0;
			for(auto e : YX[cur])
				addDelay = max(addDelay, dp[e]);
			dp[cur] = curDelay + addDelay;

			if(cur == W)
				break;

			for(auto e : XY[cur])
			{
				ind[e]--;
				if(ind[e] == 0)
					q.push(e);
			}
		}

		cout << dp[W] << '\n';
	}
}