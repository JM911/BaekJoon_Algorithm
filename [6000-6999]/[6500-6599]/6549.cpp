// 6549. 히스토그램에서 가장 큰 직사각형
// P5

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int n;
long long h[100010];

int main()
{
    setIO("");

    while(true)
    {
        cin >> n;

        if(n == 0)
            break;
        
        for(int i=1; i<n+1; i++)
        {
            cin >> h[i];
        }

        stack<int> s;
        s.push(0);
        long long ans = 0;
        for(int i=1; i<=n+1; i++)
        {
            if(s.empty() || h[i] > h[s.top()])
            {
                s.push(i);
                continue;
            }

            long long minH = h[s.top()];
            int width = 0;
            while(s.size() > 1 && h[s.top()] > h[i])
            {
                int curIdx = s.top();
                s.pop();
                int prevIdx = s.top();

                minH = min(minH, h[curIdx]);
                width += (curIdx - prevIdx);
                ans = max(ans, minH * (long long)width);
            }
            s.push(i);
        }

        cout << ans << '\n';
        fill(h, h+n+1, 0);
    }

}