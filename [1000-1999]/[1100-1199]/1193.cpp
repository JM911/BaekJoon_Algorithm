// 1193. 분수찾기
// B1

#include <bits/stdc++.h>
using namespace std;

long long X;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> X;
    long long sum = 0;
    long long count = 0;

    while(sum < X)
    {
        sum += ++count;
    }

    count++;
    long long Y = sum - X + 1;

    if(count % 2 == 1)
        cout << count - Y << '/' << Y;
    else
        cout << Y << '/' << count - Y;
}