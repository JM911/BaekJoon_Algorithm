// 1789. 수들의 합
// S5

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int S;
    cin >> S;

    long long int N = static_cast<long long>(sqrt(S * 2));

    if (N * (N + 1) / 2 > S)
        cout << N - 1;

    else
        cout << N;

    return 0;
}