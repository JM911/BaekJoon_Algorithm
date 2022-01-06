// 1915. 가장 큰 정사각형
// G4

#include <bits/stdc++.h>
using namespace std;

int n, m;
string rowNum[1010];
pair<int, int> dp[1010][1010];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> rowNum[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (rowNum[i-1][j-1] == '0')
                continue;

            dp[i][j].first = min(dp[i][j - 1].first, dp[i - 1][j - 1].first) + 1;
        }
    }

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if(rowNum[i-1][j-1] == '0')
                continue;

            dp[i][j].second = min(dp[i - 1][j].second, dp[i - 1][j - 1].second) + 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, min(dp[i][j].first, dp[i][j].second));
        }
    }

    cout << ans * ans;
} 