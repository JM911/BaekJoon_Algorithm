// 1240. 노드사이의 거리
// G5

#include <bits/stdc++.h>
using namespace std;

int N, M;
int dist[1010][1010];
vector<int> adj[1010];
bool vis[1010];
long long ans;

void MyDFS(int st, int en)
{
    vis[st] = true;

    if(st == en)
    {
        cout << ans << '\n';
        return;
    }

    for ( auto i : adj[st])
    {
        if (vis[i] == true)
            continue;

        int tmpDist = dist[st][i];

        ans += tmpDist;
        MyDFS(i, en);
        ans -= tmpDist;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i<N-1; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;

        dist[u][v] = d;
        dist[v][u] = d;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(M--)
    {
        fill(vis + 1, vis + N + 1, false);
        ans = 0;

        int u, v;
        cin >> u >> v;

        MyDFS(u, v);
    }
}