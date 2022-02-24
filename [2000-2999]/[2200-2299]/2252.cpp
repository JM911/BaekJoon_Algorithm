// 2252. 줄 세우기
// G3

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 32010

int N, M;
int ind[MAX_NUM];
vector<int> adj[MAX_NUM];
queue<int> q;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    while(M--)
    {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        ind[B]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if(ind[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for(auto t : adj[cur])
        {
            ind[t]--;

            if(ind[t] == 0)
                q.push(t);
        }
    }
}