// 1929. 소수 구하기
// S2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<int> v;

    int temp = 1;

    while (temp++ < N)
    {
        bool isPrime = true;
        for (int i = 2; i <= static_cast<int>(sqrt(temp)); i++)
        {
            if (temp % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            v.push_back(temp);
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (*it >= M)
            cout << *it << '\n';
    }

    return 0;
}
