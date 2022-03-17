// 1238. 파티
// G3

#include <bits/stdc++.h>
using namespace std;

int N, M, X;
vector<pair<int, int>> adj[1010];

int d[1010];
int tmpD[1010];
const int INF = 1e9;

struct MyCmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> X;
    fill(d, d + N + 1, INF + 10);

    while(M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> pq;
    d[X] = 0;
    pq.push({0, X});

    while (!pq.empty())
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

    for (int i = 1; i<=N; i++)
    {
        if(i == X)
            continue;

        fill(tmpD, tmpD + N + 1, INF);

        tmpD[i] = 0;
        pq.push({0, i});

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            if(tmpD[cur.second] != cur.first)
                continue;
            
            for(auto a : adj[cur.second])
            {
                if(tmpD[a.second] <= a.first + cur.first)
                    continue;

                tmpD[a.second] = a.first + cur.first;
                pq.push({tmpD[a.second], a.second});
            }
        }

        d[i] += tmpD[X];
    }

    cout << *max_element(d + 1, d + N + 1);
}