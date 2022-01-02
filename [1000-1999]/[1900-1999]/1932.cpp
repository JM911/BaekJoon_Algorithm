// 1932. 정수 삼각형
// S1

#include <bits/stdc++.h>
using namespace std;

int n;
int triangle[510][510];
int sum[510][510];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    sum[1][1] = triangle[1][1];
    ans = sum[1][1];

    sum[2][1] = sum[1][1] + triangle[2][1];
    ans = max(ans, sum[2][1]);

    sum[2][2] = sum[1][1] + triangle[2][2];
    ans = max(ans, sum[2][2]);


    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + triangle[i][j];

            if(i==n)
                ans = max(ans, sum[i][j]);
        }
    }

    cout << ans;
}s