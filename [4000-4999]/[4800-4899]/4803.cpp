// 4803. 트리
// G4

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[510];
int p[510];

bool MyDFS(int num)
{
    bool check = true;

    for(auto a : adj[num])
    {
        if(a == p[num])
            continue;
        else if(p[a] != 0)
            return false;

        p[a] = num;
        check &= MyDFS(a);
    }

    return check;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int count = 0;

    while(true)
    {
        count++;
        cin >> n >> m;

        if(n == 0)
            break;

        // 초기화
        for (int i = 0; i < 510; i++)
        {
            adj[i].clear();
            p[i] = 0;
        }

        while(m--)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if(p[i] != 0)
                continue;

            if(MyDFS(i))
                ans++;
        }

        cout << "Case " << count << ": ";

        switch(ans)
        {
        case 0:
            cout << "No trees.";
            break;
        case 1:
            cout << "There is one tree.";
            break;
        default:
            cout << "A forest of " << ans << " trees.";
            break;
        }

        cout << '\n';
    }
}