// 2075. N번째 큰 수
// G5

#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    for (int i = N; i < N * N; i++)
    {
        int tmp;
        cin >> tmp;

        if(tmp <= pq.top())
            continue;

        pq.pop();
        pq.push(tmp);
    }

    cout << pq.top();
}