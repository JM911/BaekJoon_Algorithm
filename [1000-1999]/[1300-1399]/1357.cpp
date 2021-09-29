// 1357. 뒤집힌 덧셈
// B1

#include <iostream>
using namespace std;

int Rev(int x)
{
    int rev = 0;

    while (x)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return rev;
}

int main()
{
    int x, y;
    cin >> x >> y;

    cout << Rev(Rev(x) + Rev(y));

    return 0;
}