// 9613. GCD 합
// S3

#include <bits/stdc++.h>
using namespace std;

int t, n;
int Num[110];

int GCD(int a, int b)
{
    if(b%a == 0)
        return a;

    return GCD(b % a, a);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> Num[i];
        }

        sort(Num, Num + n);
        long long ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans += GCD(Num[i], Num[j]);
            }
        }

        cout << ans << '\n';
    }
}