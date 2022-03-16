// 1507. 궁금한 민호
// G3

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 25

int N;
int dist[MAX_NUM][MAX_NUM];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> dist[i][j];
            
            if(i > j)
                ans += dist[i][j];
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if(i == j || j == k || k == i)
                    continue;

                if(dist[i][j] == 0 || dist[i][k] == 0 || dist[k][j] == 0)
                    continue;

                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    cout << -1;
                    return 0;
                }
                
                if(dist[i][j] == dist[i][k] + dist[k][j])
                {
                    ans -= dist[i][j];
                    dist[i][j] = 0;
                    dist[j][i] = 0;
                }
            }
        } 
    }

    cout << ans;
}