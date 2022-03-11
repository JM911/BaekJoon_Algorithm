// 11780. 플로이드 2
// G2

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 105

int n, m;
int d[MAX_NUM][MAX_NUM];
int p[MAX_NUM][MAX_NUM];
int q[MAX_NUM][MAX_NUM];

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

        p[a][b] = b;
        q[a][b] = 2;
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
                if(d[i][j] != 0 && d[i][j] <= d[i][k] + d[k][j])
                    continue;

                d[i][j] = d[i][k] + d[k][j];
                p[i][j] = p[i][k];
                q[i][j] = q[i][k] + q[k][j] - 1;
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << q[i][j] << ' ';

            if(d[i][j] == 0)
            {
                cout << '\n';
                continue;
            }

            int nxt = p[i][j];

            cout << i << ' ';
            while(nxt != j)
            {
                cout << nxt << ' ';
                nxt = p[nxt][j];
            }
            cout << j << '\n';
        }
    }
}