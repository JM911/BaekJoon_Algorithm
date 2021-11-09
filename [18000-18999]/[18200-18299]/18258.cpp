// 18258. 큐 2
// S4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N;

    queue<int> q;
    int temp;

    while(N--)
    {
        string command;
        cin >> command;

        if(command == "push")
        {
            cin >> temp;
            q.push(temp);
        }

        else if(command == "pop")
        {
            if(!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else
                cout << -1 << '\n';
        }

        else if(command == "size")
        {
            cout << q.size() << '\n';
        }

        else if(command == "empty")
        {
            if(q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }

        else if(command == "front")
        {
            if(!q.empty())
                cout << q.front() << '\n';
            else
                cout << -1 << '\n';
        }

        else if(command == "back")
        {
            if(!q.empty())
                cout << q.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}