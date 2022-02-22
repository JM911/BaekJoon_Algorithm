// 20955. 민서의 응급 수술
// G4

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[100010];
int p[100010];
bool vis[100010];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    while(M--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        if(vis[i] == true)
            continue;

        if(i != 1)
            ans += 2;

        queue<int> q;
        vis[i] = true;
        q.push(i);

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (auto t : adj[cur])
            {
                if(vis[t] == true)
                {
                    if(p[cur] == t)
                        continue;

                    ans++;
                    continue;
                }

                p[t] = cur;
                vis[t] = true;
                q.push(t);
            }
        }
    }

    cout << ans / 2;
}