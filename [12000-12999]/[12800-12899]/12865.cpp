// 12865. 평범한 배낭
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

int N, K;
vector<pair<int, int>> v;

int d[100010][105];

int main()
{
	setIO("");

    cin >> N >> K;
    v.resize(N);
    for(auto& a : v)
    {
        cin >> a.first >> a.second;
    }

    for(int i=N-1; i>=0; i--)
    {
        for(int w=K; w>=0; w--)
        {
            if(w >= v[i].first)
            {
                d[w][i] = max(d[w-v[i].first][i+1] + v[i].second, d[w][i+1]);
            }
            else
            {
                d[w][i] = d[w][i+1];
            }
        }
    }

    cout << d[K][0];
}