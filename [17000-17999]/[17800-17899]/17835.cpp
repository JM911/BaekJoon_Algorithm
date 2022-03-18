// 17835. 면접보는 승범이네
// G2

#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<pair<int, long long>> revRoad[100010];
vector<int> st;

long long dist[100010];
int ansIdx = 100010;
long long ansDist;

struct MyCmp
{
    bool operator()(pair<int, long long> a, pair<int, long long> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    fill(&dist[0], &dist[N + 1], 1e11 + 1);

    while(M--)
    {
        int U, V, C;
        cin >> U >> V >> C;

        revRoad[V].push_back({U, C});
    }

    while(K--)
    {
        int tmp;
        cin >> tmp;
        st.push_back(tmp);
    }

    priority_queue<pair<int, long long>, vector<pair<int, long long>>, MyCmp> pq;

    for(auto a : st)
    {
        dist[a] = 0;
        pq.push({a, 0});
    }

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        
        if(dist[cur.first] != cur.second)
            continue;
        
        for(auto a : revRoad[cur.first])
        {
            if(dist[a.first] <= cur.second + a.second)
                continue;

            dist[a.first] = cur.second + a.second;
            pq.push({a.first, dist[a.first]});
        }
    }

    for (int i = N; i >= 1; i--)
    {
        if(ansDist > dist[i])
            continue;

        ansDist = dist[i];
        ansIdx = i;
    }

    cout << ansIdx << '\n'
         << ansDist;
}