// 1790. 수 이어 쓰기 2
// S1

#include <bits/stdc++.h>
using namespace std;

int N, K;
long long target;
int order;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    long long numCount = 9;
    int count = 1;
    int tmp = K;

    while(tmp > numCount)
    {
        tmp -= numCount;
        numCount /= count;
        numCount *= 10 * (++count);
    }

    target = 1;

    for (int i = 1; i < count; i++)
    {
        target *= 10;
    }

    target += (tmp - 1) / count;
    order = count - ((tmp - 1) % count + 1);

    if(target > N)
    {
        cout << -1;
        return 0;
    }

    while(order--)
    {
        target /= 10;
    }

    cout << target % 10;
}