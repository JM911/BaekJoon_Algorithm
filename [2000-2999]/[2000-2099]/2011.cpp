// 2011. 암호코드
// S1

#include <bits/stdc++.h>
using namespace std;

string password;
int passNum[5010];
int dp[5010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> password;
    int len = password.length();

    for (int i = 1; i <= len; i++)
    {
        passNum[i] = password[i - 1] - '0';
    }

    if(passNum[1] == 0)
    {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= len; i++)
    {
        if(passNum[i] != 0)
            dp[i] += dp[i - 1];

        if(passNum[i-1] !=0 && passNum[i-1]*10 + passNum[i] <= 26)
            dp[i] += dp[i - 2];

        dp[i] %= 1000000;
    }

    cout << dp[len];
} 