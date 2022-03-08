// 13418. 학교 탐방하기
// G3

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 1010

int N, M;
vector<pair<int, int>> adj[MAX_NUM];    // cost, next

bool vis[MAX_NUM];
int maxAns, minAns;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    M++;
    while(M--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        // 오르막을 1, 내리막을 0 으로 저장
        adj[A].push_back({1 - C, B});
        adj[B].push_back({1 - C, A});
    }

    priority_queue<pair<int, int>> pq_1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_2;

    // max
    int cnt = 0;
    vis[0] = true;
    pq_1.push(adj[0][0]);

    while(cnt < N)
    {
        int curCost = pq_1.top().first;
        int nxt = pq_1.top().second;
        pq_1.pop();

        if(vis[nxt] == true)
            continue;

        cnt++;
        vis[nxt] = true;
        maxAns += curCost;
        
        for(auto a : adj[nxt])
        {
            pq_1.push(a);
        }
    }

    // min
    fill(vis, vis + N + 1, false);
    cnt = 0;
    vis[0] = true;
    pq_2.push(adj[0][0]);

    while(cnt < N)
    {
        int curCost = pq_2.top().first;
        int nxt = pq_2.top().second;
        pq_2.pop();

        if(vis[nxt] == true)
            continue;

        cnt++;
        vis[nxt] = true;
        minAns += curCost;
        
        for(auto a : adj[nxt])
        {
            pq_2.push(a);
        }
    }

    cout << maxAns * maxAns - minAns * minAns;
}