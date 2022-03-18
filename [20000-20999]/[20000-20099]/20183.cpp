// 20183. 골목 대장 호석 - 효율성 2
// G1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_NUM 100010

int N, M, A, B;
ll C;
vector<pair<int, int>> adj[MAX_NUM];    // 다음 번호, 비용

struct MyCmp
{
    bool operator()(pair<int, ll> a, pair<int, ll> b)
    {
        return a.second > b.second;
    }
};

bool IsPossible(int curMax)
{
    ll dist[MAX_NUM];
    fill(&dist[0], &dist[N + 1], 1e15 + 1);

    priority_queue<pair<int, ll>, vector<pair<int, ll>>, MyCmp> pq;
    dist[A] = 0;
    pq.push({A, 0});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        
        if(dist[cur.first] != cur.second)
            continue;
        
        for(auto a : adj[cur.first])
        {
            if(a.second > curMax)
                continue;
            
            if(dist[a.first] <= cur.second + a.second)
                continue;

            dist[a.first] = cur.second + a.second;
            pq.push({a.first, dist[a.first]});
        }
    }

    return (dist[B] <= C);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> A >> B >> C;

    while(M--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int st = 1;
    int en = 1e9;
    bool ansCheck = false;

    while(st < en)
    {
        int mid = (st + en) / 2;
        ansCheck = IsPossible(mid);

        if(!ansCheck)
            st = mid + 1;
        else
            en = mid;
    }

    if(!IsPossible(en))
        cout << -1;
    else
        cout << en;
}