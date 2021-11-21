// 16987. 계란으로 계란치기
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
pair<int, int> eggs[10];    // first: 체력, second: 공격력
int maxEgg, curEgg;

void HitEggs(int idx, int right)
{
    if(idx > right || (idx == right && curEgg+1 == N))
    {
        maxEgg = max(maxEgg, curEgg);
        return;
    }

    if(eggs[idx].first <= 0)
    {
        HitEggs(idx+1, right);
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if(eggs[i].first <= 0 || i == idx)
            continue;

        eggs[i].first -= eggs[idx].second;
        eggs[idx].first -= eggs[i].second;

        if(eggs[i].first <= 0)
            curEgg++;
        if(eggs[idx].first <= 0)
            curEgg++;

        int newRight = idx;
        for (int j = N; j>=1; j--)
        {
            if(eggs[j].first > 0)
            {
                newRight = j;
                break;
            }
        }

        HitEggs(idx + 1, newRight);

        if(eggs[i].first <= 0)
            curEgg--;
        if(eggs[idx].first <= 0)
            curEgg--;
        
        eggs[i].first += eggs[idx].second;
        eggs[idx].first += eggs[i].second;
    }
}

int main()
{
    fastio;
    cin >> N;

    eggs[0] = {1, 1};
    for (int i = 1; i <= N; i++)
    {
        cin >> eggs[i].first >> eggs[i].second;
    }

    HitEggs(1, N);

    cout << maxEgg;
}