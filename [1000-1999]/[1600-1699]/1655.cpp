// 1655. 가운데를 말해요
// G2

#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int> pqLeft;
priority_queue<int, vector<int>, greater<int>> pqRight;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    // 1
    int tmp;
    cin >> tmp;

    pqLeft.push(tmp);
    cout << pqLeft.top() << '\n';

    if(N==1)
        return 0;

    // 2
    cin >> tmp;
    
    if(tmp > pqLeft.top())
        pqRight.push(tmp);
    else
    {
        pqRight.push(pqLeft.top());
        pqLeft.pop();
        pqLeft.push(tmp);
    }

    cout << pqLeft.top() << '\n';

    while(N-- > 2)
    {
        cin >> tmp;

        int leftTop = pqLeft.top();
        int rightTop = pqRight.top();

        if(tmp > rightTop)
            pqRight.push(tmp);
        else
            pqLeft.push(tmp);

        while(pqLeft.size() > pqRight.size())
        {
            pqRight.push(pqLeft.top());
            pqLeft.pop();
        }

        while(pqLeft.size() < pqRight.size())
        {
            pqLeft.push(pqRight.top());
            pqRight.pop();
        }

        cout << pqLeft.top() << '\n';
    }
}