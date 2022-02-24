// 2623. 음악프로그램
// G2

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 1010

int N, M;
vector<int> adj[MAX_NUM];
int ind[MAX_NUM];

queue<int> q;
vector<int> ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    while(M--)
    {
        vector<int> tmpVec;
        int tmpSize;

        cin >> tmpSize;
        while(tmpSize--)
        {
            int tmp;
            cin >> tmp;
            tmpVec.push_back(tmp);
        }

        for (int i = 0; i < tmpVec.size() - 1; i++)
        {
            int u = tmpVec[i];
            int v = tmpVec[i + 1];

            adj[u].push_back(v);
            ind[v]++;
        }
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

        ans.push_back(cur);

        for(auto t: adj[cur])
        {
            ind[t]--;

            if(ind[t] == 0)
                q.push(t);
        }
    }

    if(ans.size() == N)
    {
        for(auto t: ans)
        {
            cout << t << '\n';
        }
    }

    else
    {
        cout << 0;
    }
}