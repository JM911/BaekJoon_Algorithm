// 17218. 비밀번호 만들기
// G5

#include <bits/stdc++.h>
using namespace std;

string A, B;
int dp[50][50];

int ansCount;
char ans[50];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();

    for (int i = 1; i <= lenA; i++)
    {
        for (int j = 1; j <= lenB; j++)
        {
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            ansCount = max(ansCount, dp[i][j]);
        }
    }

    while (ansCount)
    {
        bool isChecked = false;

        for (int i = 0; i <= lenA; i++)
        {
            for (int j = 0; j <= lenB; j++)
            {
                if (dp[i][j] == ansCount)
                {
                    isChecked = true;
                    lenA = i - 1;
                    lenB = j - 1;
                    ansCount--;
                    ans[ansCount] = A[i - 1];
                    break;
                }
            }

            if (isChecked)
                break;
        }
    }

    for(auto a : ans)
    {
        if(a == 0)
            break;

        cout << a;
    }
}