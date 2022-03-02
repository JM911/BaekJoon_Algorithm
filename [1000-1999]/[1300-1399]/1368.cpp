// 1368. 물대기
// G2

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 310

int N;
vector<pair<int, int>> adj[MAX_SIZE];

bool isSelected[MAX_SIZE];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int tmpCost;
        cin >> tmpCost;

        adj[0].push_back({-tmpCost, i});
        adj[i].push_back({-tmpCost, 0});
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int tmpCost;
            cin >> tmpCost;

            if(i == j)
                continue;

            adj[i].push_back({-tmpCost, j});
        }
    }

    priority_queue<pair<int, int>> pq;

    isSelected[0] = true;
    for(auto a : adj[0])
    {
        pq.push(a);
    }

    int cnt = 0;
    int ans = 0;

    while(cnt < N)
    {
        int curCost = -pq.top().first;
        int curIdx = pq.top().second;
        pq.pop();

        if(isSelected[curIdx] == true)
            continue;

        isSelected[curIdx] = true;
        cnt++;
        ans += curCost;

        for(auto a : adj[curIdx])
        {
            pq.push(a);
        }
    }

    cout << ans;
}