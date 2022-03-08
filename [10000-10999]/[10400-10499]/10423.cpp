// 10423. 전기가 부족해
// G2

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 1010

int N, M, K;
vector<pair<int, int>> adj[MAX_NUM];
vector<int> GenCity;

bool vis[MAX_NUM];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    while(K--)
    {
        int tmpCity;
        cin >> tmpCity;

        GenCity.push_back(tmpCity);
    }

    while(M--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({-w, v});
        adj[v].push_back({-w, u});
    }

    int cnt = GenCity.size();
    priority_queue<pair<int, int>> pq;

    for(auto a : GenCity)
    {
        vis[a] = true;

        for(auto b : adj[a])
        {
            if(vis[b.second] == true)
                continue;

            pq.push(b);
        }
    }

    while(cnt < N)
    {
        int curCost = -pq.top().first;
        int nxt = pq.top().second;
        pq.pop();

        if(vis[nxt] == true)
            continue;

        cnt++;
        vis[nxt] = true;
        ans += curCost;

        for(auto a : adj[nxt])
        {
            if(vis[a.second] == true)
                continue;

            pq.push(a);
        }
    }

    cout << ans;
}