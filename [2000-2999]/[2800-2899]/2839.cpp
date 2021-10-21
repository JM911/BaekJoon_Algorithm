// 2839. 설탕 배달
// B1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int a = N % 5;
    int five, three;

    switch (a)
    {
    case 0:
        five = N / 5;
        three = 0;
        break;
    case 1:
        five = N / 5 - 1;
        three = 2;
        break;
    case 2:
        five = N / 5 - 2;
        three = 4;
        break;
    case 3:
        five = N / 5;
        three = 1;
        break;
    case 4:
        five = N / 5 - 1;
        three = 3;
        break;
    }
    
    if (N == 4 || N == 7)
        cout << -1;
    else
        cout << five + three;

    return 0;
}
