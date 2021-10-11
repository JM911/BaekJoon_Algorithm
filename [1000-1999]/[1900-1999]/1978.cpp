// 1978. 소수 찾기
// S4

#include <iostream>
#include <cmath>
using namespace std;

bool IsPrimeNumber(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (IsPrimeNumber(num))
        {
            count++;
        }
    }

    cout << count;
    
    return 0;
}