// 2217. 로프
// S4

#include <bits/stdc++.h>
using namespace std;

int N;
int rope[100010];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> rope[i];
    }

    sort(rope, rope + N);

    for (int i = 0; i < N; i++)
    {
        int tmp = rope[i] * (N - i);
        ans = max(ans, tmp);
    }

    cout << ans;
}  