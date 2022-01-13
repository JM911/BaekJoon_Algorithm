#include <bits/stdc++.h>
using namespace std;

int T, M, N, x, y;

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

    cin >> T;

    while(T--)
    {
        cin >> M >> N >> x >> y;

        if(M>N)
        {
            int tmp = M;
            M = N;
            N = tmp;

            tmp = x;
            x = y;
            y = tmp;
        }

        int LCM = M / GCD(M, N) * N;

        int target = y;
        int ans = -1;

        while(target <= LCM + y)
        {
            if(target % M == x)
            {
                ans = target;
                break;
            }

            target += N;
        }

        cout << ans << '\n';
    }
}