// 1699. 제곱수의 합
// S3

#include <bits/stdc++.h>
using namespace std;

int N;
int dp[100010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(dp, dp + 100010, INT_MAX);

    queue<int> q;

    for (int i = 1; i <= 316; i++)
    {
        int idx = i * i;

        if(idx<=100000)
        {
            dp[idx] = 1;
            q.push(idx);
        }
    }

    while(!q.empty())
    {
        int curIdx = q.front();
        q.pop();

        for (int i = 1; i <= 316; i++)
        {
            int newIdx = curIdx + i * i;

            if(newIdx > 100000)
                continue;

            if(dp[newIdx] > dp[curIdx] +1)
            {
                dp[newIdx] = dp[curIdx] + 1;
                q.push(newIdx);
            }
        }
    }

    cin >> N;
    cout << dp[N];
}  