// 10773. 제로
// S4

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int K;
    cin >> K;
    stack<int> myst;

    for(int i=0; i<K; i++)
    {
        int money;
        scanf("%d", &money);

        if(money!=0)
            myst.push(money);
        else
            myst.pop();
    }

    int sum = 0;

    while(!myst.empty())
    {
        sum += myst.top();
        myst.pop();
    }

    cout << sum;

    return 0;
}
