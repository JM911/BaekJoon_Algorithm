// 14938. 서강 그라운드
// G4

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 105

int n, m, r;
int dist[MAX_NUM][MAX_NUM];
int t[MAX_NUM];

int d[MAX_NUM][MAX_NUM];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> r;

    fill(&dist[0][0], &dist[n][n+1], 500);

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    while(r--)
    {
        int a, b, l;
        cin >> a >> b >> l;

        dist[a][b] = l;
        dist[b][a] = l;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i == j || dist[i][j] <= dist[i][k] + dist[k][j])
                    continue;

                dist[i][j] = dist[i][k] + dist[k][j];
                dist[j][i] = dist[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int tmpSum = 0;

        for (int j = 1; j <= n; j++)
        {
            if(dist[i][j] > m && i != j)
                continue;

            tmpSum += t[j];
        }

        ans = max(ans, tmpSum);
    }

    cout << ans;
}