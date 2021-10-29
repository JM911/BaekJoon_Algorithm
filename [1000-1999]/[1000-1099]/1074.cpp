// 1074. Z
// S1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, r, c;
    cin >> N >> r >> c;

    int a, b;

    int arr[15] = {};

    for(int i = N-1; i>=0; i--)
    {
        a = r / pow(2, i);
        b = c / pow(2, i);

        r %= (int)pow(2, i);
        c %= (int)pow(2, i);

        arr[i] = 2 * a + b;
    }

    int ans = 0;

    for(int i=0; i<N; i++)
        ans += pow(2, 2*i) * arr[i];

    cout << ans;

    return 0;
}
