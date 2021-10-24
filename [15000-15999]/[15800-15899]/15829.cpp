// 15829. Hashing
// B2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll HashingHelper(char c, int powNum)
{
    ll num = c - 96;

    for (int i = 0; i < powNum; i++)
    {
        num *= 31;
        num %= 1234567891;
    }

    return num;
}

int main()
{
    int L;
    cin >> L;

    string str;
    cin >> str;

    ll sum = 0;

    for (int i = 0; i < L; i++)
    {
        sum += HashingHelper(str[i], i);
        sum %= 1234567891;
    }

    cout << sum;

    return 0;
}
