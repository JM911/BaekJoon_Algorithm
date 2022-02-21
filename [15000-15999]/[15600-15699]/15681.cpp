// 15681. 트리와 쿼리
// G5

#include <bits/stdc++.h>
using namespace std;

int N, R, Q;
vector<int> adj[100010];
int p[100010];
int dp[100010];

int MyDFS(int num)
{
    int ans = 1;

    for(auto a : adj[num])
    {
        if(a == p[num])
            continue;

        ans += MyDFS(a);
    }

    dp[num] = ans;
    return ans;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    p[R] = -1;
    q.push(R);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto a : adj[cur])
        {
            if(a == p[cur])
                continue;

            p[a] = cur;
            q.push(a);
        }
    }

    MyDFS(R);

    while(Q--)
    {
        int sub;
        cin >> sub;
        cout << dp[sub] << '\n';
    }
}