// 1541. 잃어버린 괄호
// S2

#include <bits/stdc++.h>
using namespace std;

string eq;
bool curState = false;
int sum, tmp;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> eq;
    int len = eq.length();

    for (int i = 0; i < len; i++)
    {
        char token = eq[i];

        switch(token)
        {
        case '+':
            if(curState)
                sum -= tmp;
            else
                sum += tmp;
            tmp = 0;
            break;
        case '-':
            if(curState)
                sum -= tmp;
            else
                sum += tmp;
            tmp = 0;
            curState = true;
            break;
        default:
            tmp *= 10;
            tmp += token - '0';
            break;
        }
    }

    if(curState)
        sum -= tmp;
    else
        sum += tmp;

    cout << sum;
}