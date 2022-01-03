// 2193. 이친수
// S3

#include <bits/stdc++.h>
using namespace std;

int N;
long long pinary[100][2];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    pinary[1][0] = 0;
    pinary[1][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        pinary[i][0] = pinary[i - 1][0] + pinary[i - 1][1];
        pinary[i][1] = pinary[i - 1][0];
    }

    cout << pinary[N][0] + pinary[N][1];
}