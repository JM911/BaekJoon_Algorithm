// 2660. 회장 뽑기
// G5

#include <bits/stdc++.h>
using namespace std;

int N;
bool mem[55][55];
int score[55][55];

bool vis[55];
int ans[55];
vector<int> cand;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    while(true)
    {
        int a, b;
        cin >> a >> b;
        
        if(a == -1 && b == -1)
            break;

        mem[a][b] = true;
        mem[b][a] = true;
    }

    for (int st = 1; st <= N; st++)
    {
        fill(vis + 1, vis + N + 1, false);
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int i = 1; i <= N; i++)
            {
                if(mem[cur][i] == false)
                    continue;
                
                if(vis[i] == true)
                    continue;

                score[st][i] = score[st][cur] + 1;
                score[i][st] = score[cur][st] + 1;

                q.push(i);
                vis[i] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j<=N; j++)
        {
            ans[i] = max(ans[i], score[i][j]);
        }
    }

    int minScore = *min_element(ans+1, ans+N+1);

    for (int i = 1; i<=N; i++)
    {
        if(ans[i] == minScore)
        {
            cand.push_back(i);
        }
    }

    cout << minScore << ' ' << cand.size() << '\n';
    
    for(auto aa : cand)
    {
        cout << aa << ' ';
    }
}