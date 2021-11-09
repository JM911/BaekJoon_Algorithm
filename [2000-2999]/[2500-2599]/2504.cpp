// 2504. 괄호의 값
// S2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    string prob;
    cin >> prob;
    int len = prob.length();

    stack<char> s;
    bool isOK = true;
    bool isFirst = true;
    int ans = 0;
    int mul = 1;

    for (int i = 0; i < len; i++)
    {
        char token = prob[i];
        switch(token)
        {
        case '(':
            isFirst = true;
            mul *= 2;
            s.push(token);
            break;

        case ')':
            if(isFirst)
            {
                isFirst = false;
                ans += mul;
            }
            mul /= 2;
            if(s.empty())
                isOK = false;
            if(!s.empty() && s.top() == '(')
                s.pop();
            break;

        case '[':
            isFirst = true;
            mul *= 3;
            s.push(token);
            break;

        case ']':
            if(isFirst)
            {
                isFirst = false;
                ans += mul;
            }
            mul /= 3;
            if(s.empty())
                isOK = false;
            if(!s.empty() && s.top() == '[')
                s.pop();
            break;
        }
    }

    if(s.empty() && isOK == true)
        cout << ans;
    else
        cout << 0;
}