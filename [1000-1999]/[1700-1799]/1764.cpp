// 1764. 듣보잡
// S4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N, M;
    cin >> N >> M;

    priority_queue<string> pqA;
    priority_queue<string> pqB;

    string temp;

    for(int i=0; i<N; i++)
    {
        cin >> temp;
        pqA.push(temp);
    }

    for(int i=0; i<M; i++)
    {
        cin >> temp;
        pqB.push(temp);
    }

    stack<string> ans;

    while(!pqA.empty() && !pqB.empty())
    {
        string a = pqA.top();
        string b = pqB.top();

        if(a.compare(b) == 0)
        {
            ans.push(a);
            pqA.pop();
            pqB.pop();
        }

        else if(a.compare(b) < 0)
            pqB.pop();

        else
            pqA.pop();
    }

    while(!pqA.empty())
        pqA.pop();

    while(!pqB.empty())
        pqB.pop();


    cout << ans.size() << '\n';

    while(!ans.empty())
    {
        cout << ans.top() << '\n';
        ans.pop();
    }

    return 0;
}
