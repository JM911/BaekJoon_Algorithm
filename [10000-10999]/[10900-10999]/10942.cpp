// 10942. 팰린드롬?
// G3

#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[2010];
bool dp[2010][2010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        dp[i][i] = true;
    }

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if(j-i == 1)
            {
                dp[i][j] = (num[i] == num[j]);
                continue;
            }

            dp[i][j] = dp[i + 1][j - 1] && (num[i] == num[j]);
        }
    }

    cin >> M;

    while(M--)
    {
        int a, b;
        cin >> a >> b;
        
        if(dp[a-1][b-1])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
} 