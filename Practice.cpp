#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N;

    long long sum = 0;
    stack<pair<int, int>> s;
    int streak = 0;
    int temp;

    cin >> temp;
    N--;
    s.push(make_pair(1, temp));

    while(N--)
    {
        
    }

    cout << sum;
}
