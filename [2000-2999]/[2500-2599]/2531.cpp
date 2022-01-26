// 2531. 회전 초밥
// S1

#include <bits/stdc++.h>
using namespace std;

int N, d, k, c;
int dish[30010];
int cnt[3010];
int ans, tmp;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++)
    {
        cin >> dish[i];
    }

    int leftIdx = 0;
    int rightIdx = k - 1;
    for (int i = 0; i < k; i++)
    {
        if(++cnt[dish[i]] == 1)
            tmp++;
    }

    ans = (cnt[c] == 0) ? tmp + 1 : tmp;

    while(true)
    {
        leftIdx++;
        rightIdx++;
        if(rightIdx >= N)
            rightIdx = 0;

        if(leftIdx >= N)
            break;

        if(--cnt[dish[leftIdx - 1]] == 0)
            tmp--;
        if(++cnt[dish[rightIdx]] == 1)
            tmp++;
        
        ans = (cnt[c] == 0) ? max(ans, tmp + 1) : max(ans, tmp);
    }

    cout << ans;
}