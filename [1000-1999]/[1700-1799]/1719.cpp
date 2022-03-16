// 1719. 택배
// G4

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 210

int n, m;
int d[MAX_NUM][MAX_NUM];
int p[MAX_NUM][MAX_NUM];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    fill(&d[0][0], &d[n][n + 1], 1000001);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        cin >> d[u][v];
        d[v][u] = d[u][v];

        p[u][v] = v;
        p[v][u] = u;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j<=n; j++)
            {
                if (i == j || d[i][j] <= d[i][k] + d[k][j])
                    continue;

                d[i][j] = d[i][k] + d[k][j];
                d[j][i] = d[i][j];

                p[i][j] = p[i][k];
                p[j][i] = p[j][k];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            if(i == j)
                cout << "- ";
            else
                cout << p[i][j] << ' ';
        }
        cout << '\n';
    }
}