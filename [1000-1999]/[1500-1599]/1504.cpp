// 1504. 특정한 최단 경로
// G4

#include <bits/stdc++.h>
using namespace std;

int N, E, v1, v2;
vector<pair<int, int>> adj[810];

int d[810];
const int INF = 1e8 + 1;

int ans1, ans2;

struct MyCmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> pq;

void MyDijk(int st)
{
    fill(d, d + N + 1, INF);
    d[st] = 0;
    pq.push({0, st});
    
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(d[cur.second] != cur.first)
            continue;
        
        for(auto a : adj[cur.second])
        {
            if(d[a.second] <= a.first + cur.first)
                continue;

            d[a.second] = a.first + cur.first;
            pq.push({d[a.second], a.second});
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> E;

    while(E--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    // 1 -> v1, v2
    MyDijk(1);

    ans1 += d[v1];
    ans2 += d[v2];

    // v1, v2 -> N
    MyDijk(N);

    ans1 += d[v2];
    ans2 += d[v1];

    // v1 <-> v2
    MyDijk(v1);

    ans1 += d[v2];
    ans2 += d[v2];

    // ans
    int ans = min(ans1, ans2);

    if(ans > INF-1)
        ans = -1;

    cout << ans;
}