// 2467. 용액
// G5

#include "bits/stdc++.h"
using namespace std;

int N;
int liq[100010];
pair<int, int> ans;
int curSum = INT_MAX;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> liq[i];
    }

    for (int i = 0; i < N; i++)
    {
        int tmp = -liq[i];
        int lidx = lower_bound(liq, liq + N, tmp) - liq;

        if(lidx-1 != i && lidx > 0 && curSum > abs(liq[lidx-1] + liq[i]))
        {
            curSum = abs(liq[lidx-1] + liq[i]);
            ans = {liq[min(i, lidx - 1)], liq[max(i, lidx - 1)]};
        }

        if (lidx != i && lidx < N && curSum > abs(liq[lidx] + liq[i]))
        {
            curSum = abs(liq[lidx] + liq[i]);
            ans = {liq[min(i, lidx)], liq[max(i, lidx)]};
        }
    }

    cout << ans.first << ' ' << ans.second;
}