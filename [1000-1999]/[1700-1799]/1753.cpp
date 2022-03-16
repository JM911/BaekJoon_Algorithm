// 1753. 최단경로
// G5

#include <bits/stdc++.h>
using namespace std;

int V, E, K;
vector<pair<int, int>> adj[20010];      // 거리, 다음 정점
int dist[20010];

priority_queue<pair<int, int>> pq;
bool vis[20010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V >> E >> K;
    fill(dist, dist + V + 1, 10000001);

    while(E--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    dist[K] = 0;
    pq.push({0, K});

    while(!pq.empty())
    {
        int curDist = -pq.top().first;
        int curPos = pq.top().second;
        pq.pop();

        if(vis[curPos] == true)
            continue;

        vis[curPos] = true;

        for(auto a : adj[curPos])
        {
            if(dist[a.second] <= curDist + a.first)
                continue;

            dist[a.second] = curDist + a.first;
            pq.push({-dist[a.second], a.second});
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if(dist[i] > 10000000)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}