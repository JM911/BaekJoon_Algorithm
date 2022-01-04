// 9461. 파도반 수열
// S3

#include <bits/stdc++.h>
using namespace std;

int T, N;
long long P[110];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;

    for (int i = 6; i <= 100; i++)
    {
        P[i] = P[i - 1] + P[i - 5];
    }

    while (T--)
    {
        cin >> N;
        cout << P[N] << '\n';
    }
}