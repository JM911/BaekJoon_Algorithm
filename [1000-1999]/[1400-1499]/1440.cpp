// 1440. 타임 머신
// B2

#include <iostream>
using namespace std;

bool hourCheck(int num)
{
    if (num <= 12 && num >= 1)
        return 1;
    else return 0;
}

int main()
{
    char timecheck[10];
    cin >> timecheck;

    int a, b, c;
    a = ((int)timecheck[0] - 48) * 10 + (int)timecheck[1] - 48;
    b = ((int)timecheck[3] - 48) * 10 + (int)timecheck[4] - 48;
    c = ((int)timecheck[6] - 48) * 10 + (int)timecheck[7] - 48;

    int methodNum = 0;
    if ((hourCheck(a) + hourCheck(b) + hourCheck(c) == 0)
        || (a > 59 || b > 59 || c > 59) || (a == 0 && b == 0 && c == 0))
    {
        methodNum = 0;
    }

    else if (hourCheck(a) + hourCheck(b) + hourCheck(c) == 1)
    {
        methodNum = 2;
    }

    else if (hourCheck(a) + hourCheck(b) + hourCheck(c) == 2)
    {
        methodNum = 4;
    }

    else
    {
        methodNum = 6;
    }

    cout << methodNum;

    return 0;
}