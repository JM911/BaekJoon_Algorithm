// 2240. 자두나무
// G5

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int T, W;
int p[1010];
int d[1010][32];

int e[1010][3];
int ans;

int main()
{
	setIO("");

	cin >> T >> W;

	int totalOne = 0;
	for(int i=1; i<=T; i++)
	{
		cin >> p[i];
		if(p[i]==1)
			totalOne++;
	}

	e[1][0] = totalOne;
	e[1][1] = T-totalOne;

	for(int i=2; i<= T; i++)
	{
		e[i][0] = p[i-1]==1 ? e[i-1][0]-1 : e[i-1][0];
		e[i][1] = p[i-1]==2 ? e[i-1][1]-1 : e[i-1][1];
	}

	d[1][0] = e[1][0];
	d[1][1] = e[1][1];

	for(int i=2; i<=T; i++)
	{
		for(int j=0; j<=min(i, W); j++)
		{
			d[i][j] = d[i-1][j];
			if(j>0)
			{
				d[i][j] = max(d[i-1][j], d[i-1][j-1] - e[i][(j-1)%2] + e[i][j%2]);
			}
		}
	}

	for(int i=0; i<=W; i++)
	{
		ans = max(ans, d[T][i]);
	}

	cout << ans;
}