// 1647. 도시 분할 계획
// G4

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> adj[100010];     // cost, next

bool vis[100010];
int maxCost;
int sum;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    while(M--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        adj[A].push_back({-C, B});
        adj[B].push_back({-C, A});
    }

    priority_queue<pair<int, int>> pq;

    int count = 1;
    vis[1] = true;
    for(auto a : adj[1])
    {
        pq.push(a);
    }

    while (count < N)
    {
        int curCost = -pq.top().first;
        int nxt = pq.top().second;
        pq.pop();

        if(vis[nxt] == true)
            continue;

        count++;
        vis[nxt] = true;

        sum += curCost;
        maxCost = max(maxCost, curCost);

        for(auto a : adj[nxt])
        {
            pq.push(a);
        }
    }

    cout << sum - maxCost;
}