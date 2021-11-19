// 6198. 옥상 정원 꾸미기
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N;

    stack<int> s;
    long long count = 0;

    while(N--)
    {
        int temp;
        cin >> temp;

        while(!s.empty() && s.top() <= temp)
            s.pop();

        count += (long long)s.size();
        s.push(temp);
    }

    cout << count;

    return 0;
}
