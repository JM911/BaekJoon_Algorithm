// 2493. 탑
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N;

    stack<pair<int, int>> s;    // first: 탑 순서 번호, second: 탑 높이
    queue<int> q;
    int count = 0;

    while(N--) 
    {
        int temp;
        cin >> temp;
        count++;

        while(!s.empty())
        {
            if(s.top().second >= temp)
                break;

            s.pop();
        }

        if(!s.empty())
            q.push(s.top().first);
        else
            q.push(0);

        s.push(make_pair(count, temp));
    }

    while(!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}
