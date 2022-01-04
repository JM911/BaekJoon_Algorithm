// 10844. 쉬운 계단 수
// S1

#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[110][10];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][0] %= 1000000000;

        for (int j = 1; j <= 8; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            dp[i][j] %= 1000000000;
        }

        dp[i][9] = dp[i - 1][8];
        dp[i][9] %= 1000000000;
    }

    long long ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += dp[N][i];
        ans %= 1000000000;
    }

    cout << ans;
}  