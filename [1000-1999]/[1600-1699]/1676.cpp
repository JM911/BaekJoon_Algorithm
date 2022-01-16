// 1676. 팩토리얼의 0의 개수
// S4

#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int tmp = i;

        while(tmp%5 == 0)
        {
            ans++;
            tmp /= 5;
        }
    }

    cout << ans;
}