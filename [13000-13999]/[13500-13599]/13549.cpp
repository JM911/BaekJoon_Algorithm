// 13549. 숨바꼭질3
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

pair<bool, int> line[100001];

int main()
{
    fastio;
    int N, K;
    cin >> N >> K;

    queue<int> q;
    q.push(N);
    line[N] = pair<bool, int>(true, 0);

    while(!q.empty())
    {
        int idx = q.front();
        
        while(idx !=0 && idx*2 <= 100000)
        {
            if(line[idx*2].first == false)
            {
                line[idx*2] = pair<bool, int>(true, line[idx].second);
                q.push(idx*2);
            }
            idx *= 2;
        }

        idx = q.front();

        if(idx-1>=0)
        {
            if(line[idx-1].first == false)
            {
                line[idx-1] = pair<bool, int>(true, line[idx].second + 1);
                q.push(idx-1);
            }
        }

        if(idx+1 <= 100000)
        {
            if(line[idx+1].first == false)
            {
                line[idx+1] = pair<bool, int>(true, line[idx].second + 1);
                q.push(idx+1);
            }
        }

        q.pop();
    }

    cout << line[K].second;


    return 0;
}
