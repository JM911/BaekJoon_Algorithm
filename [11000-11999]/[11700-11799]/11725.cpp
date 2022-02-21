// 11725. 트리의 부모 찾기
// S2

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[100010];
int p[100010];

void MyDFS(int num)
{
    for(int a : adj[num])
    {
        if(p[a] != 0)
            continue;

        p[a] = num;
        MyDFS(a);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    p[1] = -1;
    MyDFS(1);

    for (int i = 2; i <= N; i++)
    {
        cout << p[i] << '\n';
    }
}