// 1260. DFS와 BFS
// S2

#include <bits/stdc++.h>
using namespace std;

int N, M, V;
bool adj[1010][1010];
//vector<int> adj[1010];
bool isVisited[1010];

void MyDFS(int v)
{
    isVisited[v] = true;
    cout << v << ' ';

    for (int i = 1; i <= N; i++)
    {
        if(adj[i][v] == false)
            continue;
        if(isVisited[i])
            continue;
        MyDFS(i);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> V;

    while(M--)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true;
    }

    MyDFS(V);
    cout << '\n';
    fill(isVisited + 1, isVisited + N + 1, false);

    queue<int> q;
    q.push(V);
    isVisited[V] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int i = 1; i <= N; i++)
        {
            if(adj[i][cur] == false)
                continue;
            if(isVisited[i])
                continue;
            q.push(i);
            isVisited[i] = true;
        }
    }
}