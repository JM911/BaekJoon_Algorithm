#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, w, L;
int truckW[20];
int truckPos[20];
int curL;
int firstIdx;
int lastIdx;

void ProcedeOneSec()
{
    for (int i = firstIdx; i <= lastIdx; i++)
    {
        truckPos[i]++;
    }

    if(truckPos[firstIdx] == w+1)
    {
        curL += truckW[firstIdx];
        firstIdx++;
    }

    if (lastIdx+1 < n && curL >= truckW[lastIdx + 1])
    {
        lastIdx++;
        if(truckPos[lastIdx-1] != 1) truckPos[lastIdx]++;
        curL -= truckW[lastIdx];
    }
}

int main()
{
    fastio;
    cin >> n >> w >> L;

    for (int i = 0; i < n; i++)
    {
        cin >> truckW[i];
    }

    curL = L - truckW[0];

    int ans = 0;
    while(truckPos[n-1] != w+1)
    {
        ans++;
        ProcedeOneSec();
    }

    cout << ans;

    return 0;
}