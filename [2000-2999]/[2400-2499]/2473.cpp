// 2473. 세 용액
// G4

#include "bits/stdc++.h"
using namespace std;

int N;
long long liq[5010];
long long minusLiq[5010];
tuple<int, int, int> ansIdx;
long long curSum = LONG_LONG_MAX;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> liq[i];
    }

    sort(liq, liq + N, greater<int>());

    for (int i = 0; i < N; i++)
    {
        minusLiq[i] = -liq[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            long long tmp = liq[i] + liq[j];
            int lidx = lower_bound(minusLiq + j + 1, minusLiq + N, tmp) - minusLiq;

            if(lidx-1 != j && lidx > 0 && curSum > abs(liq[lidx-1] + tmp))
            {
                curSum = abs(liq[lidx-1] + tmp);
                ansIdx = {i, j, lidx-1};
            }

            if (lidx != j && lidx < N && curSum > abs(liq[lidx] + tmp))
            {
                curSum = abs(liq[lidx] + tmp);
                ansIdx = {i, j, lidx};
            }
        }
    }

    cout << liq[get<2>(ansIdx)] << ' ' << liq[get<1>(ansIdx)] << ' ' << liq[get<0>(ansIdx)];
}