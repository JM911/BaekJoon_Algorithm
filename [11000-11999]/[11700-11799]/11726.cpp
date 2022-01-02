// 11726. 2xn 타일링
// S1

#include <bits/stdc++.h>
using namespace std;

int n;
long long ans[1010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    ans[1] = 1;
    ans[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        ans[i] = ans[i - 2] + ans[i - 1];
        ans[i] %= 10007;
    }

    cout << ans[n];
}