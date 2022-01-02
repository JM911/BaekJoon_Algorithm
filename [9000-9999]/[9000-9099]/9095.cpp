// 9095. 1, 2, 3 더하기
// S3

#include "bits/stdc++.h"
using namespace std;

int T, n;
int ans[12];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;

    for (int i = 4; i <= 10; i++)
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];

    cin >> T;

    while(T--)
    {
        cin >> n;

        cout << ans[n] << '\n';
    }
}