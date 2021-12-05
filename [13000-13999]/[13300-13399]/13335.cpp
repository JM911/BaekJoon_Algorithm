// 13335. 트럭
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, w, L;
int truckW[1100];
int curL;

int main()
{
    fastio;
    cin >> n >> w >> L;

    for (int i = 0; i < n; i++)
    {
        cin >> truckW[i];
    }

    queue<int> bridge;

    for (int i = 0; i < w; i++)
    {
        bridge.push(0);
    }

    curL = L;
    int nextIdx = 0;
    int ans = 0;

    while(!bridge.empty())
    {
        ans++;
        if(bridge.front() != 0)
        {
            curL += bridge.front();
        }

        bridge.pop();

        if(nextIdx != n)
        {
            if (curL >= truckW[nextIdx])
            {
                bridge.push(truckW[nextIdx]);
                curL -= truckW[nextIdx];
                nextIdx++;
            }
            
            else
                bridge.push(0);
        }
    }

    cout << ans;

    return 0;
}