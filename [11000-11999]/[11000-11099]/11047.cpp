// 11047. 동전 0
// S2

#include <bits/stdc++.h>
using namespace std;

int N, K;
int coin[15];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        ans += K / coin[i];
        K %= coin[i];
    }

    cout << ans;
} 