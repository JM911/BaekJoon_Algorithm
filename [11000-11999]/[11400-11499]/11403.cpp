// 11403. 경로 찾기
// S1

#include <bits/stdc++.h>
using namespace std;

int N;
int gp[110][110];
int ans[110][110];
bool vis[110];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> gp[i][j];
        }
    }

    for (int st = 0; st < N; st++)
    {
        fill(vis, vis + N, false);
        stack<int> s;
        s.push(st);

        while(!s.empty())
        {
            int cur = s.top();
            s.pop();

            for (int i = 0; i < N; i++)
            {
                if(gp[cur][i] == 0)
                    continue;
                if(vis[i] == true)
                    continue;

                vis[i] = true;
                ans[st][i] = true;
                s.push(i);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}