// 1766. 문제집
// G2

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 32010

int N, M;
vector<int> adj[MAX_NUM];
int ind[MAX_NUM];

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    while(M--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        ind[v]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if(ind[i] == 0)
            pq.push(i);
    }

    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << ' ';

        for(auto t : adj[cur])
        {
            ind[t]--;

            if(ind[t] == 0)
                pq.push(t);
        }
    }
}