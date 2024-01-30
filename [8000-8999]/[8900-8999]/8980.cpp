// 8980. 택배
// G1

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

int N, C, M;
vector<pair<int, int>> pack[2020];
int ans;
unordered_map<int, int> um;

void RefreshPack(int startIdx)
{
    int remainPack = C;

    for(int i=startIdx; i<=N; i++)
    {
        if(um.find(i) == um.end()) continue;

        if(um[i] >= remainPack)
        {
            um[i] = remainPack;
            for(int j=i+1; j<=N; j++) um.erase(j);
            break;
        }
        else
        {
            remainPack -= um[i];
        }
    }
}

int main()
{
	setIO("");

    cin >> N >> C >> M;
    
    for(int i=0; i<M; i++)
    {
        int s, e, num;
        cin >> s >> e >> num;

        pack[s].push_back({e, num});
    }

    for(int i=1; i<=N; i++)
    {
        if(um.find(i) != um.end())
        {
            ans += um[i];
            um.erase(i);
        }

        for(auto a : pack[i])
        {
            um[a.first] += a.second;
        }
        RefreshPack(i+1);
    }

    cout << ans;
}