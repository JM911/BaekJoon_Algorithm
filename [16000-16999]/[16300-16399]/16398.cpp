// 16398. 행성 연결
// G4

#include <bits/stdc++.h>
using namespace std;

int N;
int cost[1010][1010];

bool vis[1010];
long long ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> cost[i][j];
        }
    }

    priority_queue<pair<int, int>> pq;    // cost, next

    int cnt = 1;
    vis[1] = true;

    for (int i = 1; i <= N; i++)
    {
        if(i == 1)
            continue;

        pq.push({-cost[1][i], i});
    }

    while(cnt < N)
    {
        int curCost = -pq.top().first;
        int nxt = pq.top().second;
        pq.pop();

        if(vis[nxt] == true)
            continue;

        cnt++;
        vis[nxt] = true;
        ans += curCost;

        for (int i = 1; i <= N; i++)
        {
            if(i == nxt)
                continue;

            pq.push({-cost[nxt][i], i});
        }
    }

    cout << ans;
}