// 1389. 케빈 베이컨의 6단계 법칙
// S1

#include <bits/stdc++.h>
using namespace std;

int N, M;
bool fr[110][110];

bool vis[110];
int kbNum[110][110];
int ansNum;
int ansVal = INT_MAX;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    while(M--)
    {
        int A, B;
        cin >> A >> B;

        fr[A][B] = true;
        fr[B][A] = true;
    }

    for (int i = 1; i <= N; i++)
    {
        fill(vis, vis + N + 1, false);
        queue<int> q;

        vis[i] = true;
        q.push(i);

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int j = 1; j <= N; j++)
            {
                if(vis[j] == true)
                    continue;
                
                if(fr[cur][j] == false)
                    continue;

                vis[j] = true;
                kbNum[i][j] = kbNum[i][cur] + 1;
                q.push(j);
            }
        }
    }

    for (int i = N; i >= 1; i--)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            sum += kbNum[i][j];
        }

        if(sum <= ansVal)
        {
            ansVal = sum;
            ansNum = i;
        }
    }

    cout << ansNum;
}