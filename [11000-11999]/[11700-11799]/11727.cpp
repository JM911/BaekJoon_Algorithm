// 11727. 2xn 타일링 2
// S3

#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
        dp[i] %= 10007;
    }

    cout << dp[n];
}