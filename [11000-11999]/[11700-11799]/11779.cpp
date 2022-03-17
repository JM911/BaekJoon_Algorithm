// 11779. 최소비용 구하기 2
// G3

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1010];
int s, e;

int d[1010];
int p[1010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    fill(d, d + n + 1, 1e9 + 1);

    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    cin >> s >> e;

    priority_queue<pair<int, int>> pq;
    
    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty())
    {
        int curDist = -pq.top().first;
        int curPos = pq.top().second;
        pq.pop();

        if(d[curPos] != curDist)
            continue;
        
        for(auto a : adj[curPos])
        {
            if(d[a.second] <= curDist + a.first)
                continue;

            d[a.second] = curDist + a.first;
            pq.push({-d[a.second], a.second});
            p[a.second] = curPos;
        }
    }

    int tmp = e;
    stack<int> ansPath;

    while(tmp > 0)
    {
        ansPath.push(tmp);
        tmp = p[tmp];
    }

    cout << d[e] << '\n';
    cout << ansPath.size() << '\n';

    while(!ansPath.empty())
    {
        cout << ansPath.top() << ' ';
        ansPath.pop();
    }
}