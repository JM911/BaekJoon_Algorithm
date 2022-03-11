// 11404. 플로이드
// G4

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 105

int n, m;
int d[MAX_NUM][MAX_NUM];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> m;

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(d[a][b] != 0)
            d[a][b] = min(d[a][b], c);
        else
            d[a][b] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        // i -> k -> j
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(d[i][k] == 0 || d[k][j] == 0 || i == j)
                    continue;
                if(d[i][j] != 0 && d[i][j] < d[i][k] + d[k][j])
                    continue;

                d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}