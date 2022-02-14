// 1707. 이분 그래프
// G4

#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector<int> g[20010];
int group[20010];

bool MyFunc()
{
    for (int st = 1; st <= V; st++)
    {
        if(group[st] != 0)
            continue;

        queue<int> q;
        group[st] = 1;
        q.push(st);

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            int curGroup = group[cur];

            for(auto a : g[cur])
            {
                if(group[a] != 0)
                {
                    if(group[a] == curGroup)
                        return false;
                    else
                        continue;
                }

                group[a] = curGroup % 2 + 1;
                q.push(a);
            }
        }
    }

    return true;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> K;

    while(K--)
    {
        for (int i = 1; i <= V; i++)
        {
            g[i].clear();
        }

        fill(group, group + V + 1, 0);

        cin >> V >> E;

        while(E--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if(MyFunc())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}