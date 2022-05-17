// 11279. 최대 힙
// S2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<int> pq;

    while(N--)
    {
        int x;
        cin >> x;

        if(x == 0)
        {
            if(pq.empty())
                cout << '0';
            else
            {
                cout << pq.top();
                pq.pop();
            }

            cout << '\n';
        }

        else
        {
            pq.push(x);
        }
    }
}