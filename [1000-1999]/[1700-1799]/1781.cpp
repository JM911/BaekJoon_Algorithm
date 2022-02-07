// 1781. 컵라면
// G2

#include <bits/stdc++.h>
using namespace std;

int N;
int curIdx;
int curDay;
pair<int, int> pc[200010];
int ans;

bool MyComp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    curDay = N;

    for (int i = 0; i < N; i++)
    {
        cin >> pc[i].first >> pc[i].second;
    }

    sort(pc, pc + N, MyComp);
    priority_queue<int> pq;

    while(curDay > 0)
    {
        while(curIdx < N && pc[curIdx].first >= curDay)
        {
            pq.push(pc[curIdx].second);
            curIdx++;
        }

        if(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        curDay--;
    }

    cout << ans;
}