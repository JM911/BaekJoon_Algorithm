// 11562. 백양로 브레이크
// G4

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 260

int n, m, k;
int dist[MAX_NUM][MAX_NUM];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    fill(&dist[0][0], &dist[n][n + 1], 1000000);

    while(m--)
    {
        int u, v, b;
        cin >> u >> v >> b;

        dist[u][v] = 1;

        if(b == 0)
            dist[v][u] = 1000;
        else
            dist[v][u] = 1;
    }

    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i == j || dist[i][j] <= dist[i][l] + dist[l][j])
                    continue;

                dist[i][j] = dist[i][l] + dist[l][j];
            }
        }
    }

    cin >> k;
    while(k--)
    {
        int s, e;
        cin >> s >> e;

        if(s == e)
            cout << 0 << '\n';
        else
            cout << dist[s][e] / 1000 << '\n';
    }
}