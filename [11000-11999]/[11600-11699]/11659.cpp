// 11659. 구간 합 구하기 4
// S3

#include <bits/stdc++.h>
using namespace std;

int N, M;
int sum[100010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i<=N; i++)
    {
        int tmp;
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
    }

    while(M--)
    {
        int i, j;
        cin >> i >> j;

        cout << sum[j] - sum[i - 1] << '\n';
    }
}