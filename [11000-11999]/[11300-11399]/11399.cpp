// 11399. ATM
// S3

#include <bits/stdc++.h>
using namespace std;

int N, ans;
int waitTime[1010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> waitTime[i];
    }

    sort(waitTime, waitTime + N);

    for (int i = 0; i < N; i++)
    {
        ans += waitTime[i] * (N - i);
    }

    cout << ans;
}  