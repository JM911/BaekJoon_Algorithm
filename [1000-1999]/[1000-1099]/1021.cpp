// 1021. 회전하는 큐
// S4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    int num = 0;
    int ans = 0;

    for (int i = 1; i <= N; i++)
        dq.push_back(i);

    while (M--)
    {
        int target;
        cin >> target;

        int count = 0;
        for (int i = 0; i < N - num; i++)
        {
            int temp = dq.front();

            if (temp == target)
                break;

            dq.pop_front();
            dq.push_back(temp);
            count++;
        }
        dq.pop_front();

        if (count <= (N - num) / 2)
            ans += count;
        else
            ans += (N - num) - count;

        num++;
    }

    cout << ans;

    return 0;
}