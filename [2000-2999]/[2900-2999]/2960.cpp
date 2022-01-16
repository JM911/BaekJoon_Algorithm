// 2960. 에라토스테네스의 체
// S4

#include <bits/stdc++.h>
using namespace std;

int N, K;
bool isDeleted[1010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    int idx = 1;
    int count = 0;
    int ans = 0;

    while(true)
    {
        if(isDeleted[++idx] == true)
            continue;

        for (int i = 1; idx * i <= N; i++)
        {
            if(isDeleted[idx * i] == true)
                continue;

            ans = idx * i;
            isDeleted[idx * i] = true;
            count++;

            if(count == K)
                break;
        }

        if(count == K)
            break;
    }

    cout << ans;
}