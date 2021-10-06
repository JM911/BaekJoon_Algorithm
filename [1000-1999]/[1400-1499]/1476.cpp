// 1476. 날짜 계산
// S5

#include <iostream>
using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;

    int a = 1;

    while (true)
    {
        if (a % 15 == E % 15)
        {
            if (a % 28 == S % 28)
            {
                if (a % 19 == M % 19)
                    break;
                else
                    a++;
            }
            else
                a++;
        }
        else
            a++;
    }

    cout << a;

    return 0;
}