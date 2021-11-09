// 3986. 좋은 단어
// S4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N;

    stack<char> s;
    int ans = 0;

    while(N--)
    {
        string word;
        cin >> word;

        int len = word.length();

        for (int i = 0; i < len; i++)
        {
            char token = word[i];
            if(s.empty())
                s.push(token);

            else
            {
                if(s.top() == token)
                    s.pop();
                else
                    s.push(token);
            }
        }

        if(s.empty())
            ans++;

        while(!s.empty())
            s.pop();
    }

    cout << ans;

    return 0;
}