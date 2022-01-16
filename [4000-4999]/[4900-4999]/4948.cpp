// 4948. 베르트랑 공준
// S2

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 250000

bool isPrimeNum[260000];
bool isDeleted[260000];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int idx = 2; idx <= MAX_NUM; idx++)
    {
        if(isDeleted[idx])
            continue;

        isPrimeNum[idx] = true;

        for (int i = 1; i * idx <= MAX_NUM; i++)
        {
            isDeleted[idx * i] = true;
        }
    }

    int n;
    cin >> n;

    while(n)
    {
        int ans = 0;

        for (int i = n + 1; i <= 2 * n; i++)
        {
            if(isPrimeNum[i])
                ans++;
        }

        cout << ans << '\n';

        cin >> n;
    }
}