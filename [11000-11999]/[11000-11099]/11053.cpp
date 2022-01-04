// 11053. 가장 긴 증가하는 부분 수열
// S2

#include <bits/stdc++.h>
using namespace std;

int N;
int A[1010];
int dp[1010];
int maxLen;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if(A[j] > A[i])
                dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    for (int i = 0; i < N; i++)
    {
        maxLen = max(maxLen, dp[i]);
    }

    cout << maxLen;
}