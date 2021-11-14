// 1629. 곱셈
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int A, B, C;
    cin >> A >> B >> C;

    long long modArr[31];
    int binB[31];

    for (int i = 0; i < 31; i++)
    {
        binB[i] = B % 2;
        B /= 2;
    }

    modArr[0] = A % C;

    for (int i = 1; i < 31; i++)
    {
        modArr[i] = modArr[i - 1] * modArr[i - 1] % C;
    }

    long long ans = 1;

    for (int i = 0; i < 31; i++)
    {
        if(binB[i])
        {
            ans *= modArr[i];
            ans %= C;
        }
    }

    cout << ans;
}
