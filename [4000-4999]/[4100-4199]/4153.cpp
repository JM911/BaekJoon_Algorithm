// 4153. 직각삼각형
// B3

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    
    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        else
        {
            int _max = max(max(a, b), c);
            int _min = min(min(a, b), c);
            int _mid = a + b + c - _max - _min;

            if (_max * _max == _min * _min + _mid * _mid)
                cout << "right" << endl;
            else
                cout << "wrong" << endl;
        }
    }

    return 0;
}