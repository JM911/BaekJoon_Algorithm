// 17298. 오큰수
// G4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N;

    stack<int> A;
    stack<int> NGE;
    stack<int> ans;

    int temp;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        A.push(temp);
    }

    while (!A.empty())
    {
        while (!NGE.empty() && NGE.top() <= A.top())
            NGE.pop();

        if (NGE.empty())
            ans.push(-1);
        else
            ans.push(NGE.top());

        NGE.push(A.top());
        A.pop();
    }

    while(!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}