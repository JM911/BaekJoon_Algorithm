// 2609. 최대공약수와 최소공배수
// S5

#include <iostream>
#include <cmath>
using namespace std;

int MaxCommonMul(int a, int b)
{
    int ret;

    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
            ret = i;
    }

    return ret;
}

int MinCommonDiv(int a, int b)
{
    int ret = 0;
    int _max = max(a, b);

    for (int i = 1; i <= min(a, b); i++)
    {
        if (_max * i % min(a, b) == 0)
        {
            ret = i;
            break;
        }
    }
    
    return _max * ret;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << MaxCommonMul(a, b) << endl << MinCommonDiv(a, b);

    return 0;
}