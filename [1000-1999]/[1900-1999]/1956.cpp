// 1956. 운동
// G4

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 410

int V, E;
int dist[MAX_NUM][MAX_NUM];

int ans = INT_MAX;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;
    fill(&dist[0][0], &dist[V][V + 1], 5000000);

    while (E--)
    {
        int a, b;
        cin >> a >> b;

        cin >> dist[a][b];
    }

    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if(i == j || dist[i][j] <= dist[i][k] + dist[k][j])
                    continue;

                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if(i == j)
                continue;

            if(dist[i][j] == 5000000 || dist[j][i] == 5000000)
                continue;

            int tmp = dist[i][j] + dist[j][i];
            
            if(tmp < ans)
                ans = tmp;
        }
    }

    if(ans == INT_MAX)
        ans = -1;

    cout << ans;
}