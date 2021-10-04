// 1094. 막대기
// S5

#include <iostream>
using namespace std;

int main()
{
    int X;
    cin >> X;

    int count = 0;

    while (X != 0)
    {
        int tempStick = 1;

        while (tempStick <= X)
        {
            tempStick *= 2;
        }

        tempStick /= 2;
        X -= tempStick;
        count++;
    }

    cout << count;

    return 0;
}