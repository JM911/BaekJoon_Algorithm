// 1774. 우주신과의 교감
// G3

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 1010

int N, M;
pair<int, int> coord[MAX_NUM];
double dist[MAX_NUM][MAX_NUM];

bool vis[MAX_NUM];
double ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> coord[i].first >> coord[i].second;
    }

    for (int i = 1; i <= N-1; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            long long x = coord[i].first - coord[j].first;
            long long y = coord[i].second - coord[j].second;

            long long tmpDist = x * x + y * y;
            double tmpDistD = sqrt(tmpDist);
            dist[i][j] = tmpDistD;
            dist[j][i] = tmpDistD;
        }
    }

    while (M--)
    {
        int a, b;
        cin >> a >> b;

        dist[a][b] = 0;
        dist[b][a] = 0;
    }

    priority_queue<pair<double, int>> pq;    // dist, next

    int cnt = 1;
    vis[1] = true;

    for (int i = 1; i <= N; i++)
    {
        if(i == 1)
            continue;

        pq.push({-dist[1][i], i});
    }

    while(cnt < N)
    {
        double curDist = -pq.top().first;
        int nxt = pq.top().second;
        pq.pop();

        if(vis[nxt] == true)
            continue;
        
        cnt++;
        vis[nxt] = true;
        ans += curDist;

        for (int i = 1; i <= N; i++)
        {
            if(vis[i] == true)
                continue;

            pq.push({-dist[nxt][i], i});
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;
}