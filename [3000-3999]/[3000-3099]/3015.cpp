// 3015. 오아시스 재결합
// G1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N;

    long long sum = 0;
    stack<int> s;
    unordered_map<int, int> um;
    int streak = 0;
    int temp;

    cin >> temp;
    N--;
    s.push(temp);
    um[temp]++;

    while(N--)
    {
        cin >> temp;

        while(!s.empty() && s.top() <= temp)
        {
            if(s.top() < temp)
            {
                sum += um[s.top()];
                um[s.top()] = 0;
                s.pop();
            }

            else
            {
                sum += um[s.top()];
                s.pop();
            }
        }

        if(!s.empty() && s.top() > temp)
        {
            sum++;
        }

        s.push(temp);
        um[temp]++;
    }

    cout << sum;
}
