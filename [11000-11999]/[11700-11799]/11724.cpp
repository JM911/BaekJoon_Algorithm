// 11724. 연결 요소의 개수
// S2

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[1010];
bool isVisited[1010];
int ans;
queue<int> q;

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

    for (int i = 1; i<=N; i++)
    {
        if(isVisited[i])
            continue;

        ans++;
        isVisited[i] = true;
        q.push(i);

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for(int a : adj[cur])
            {
                if(isVisited[a])
                    continue;
                isVisited[a] = true;
                q.push(a);
            }
        }
    }

    cout << ans;
}