// 2231. 분해합
// B2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int M = 1;
    while (M < N)
    {
        int sum = 0;

        for (int i = 0; i < 7; i++)
        {
            int temp = M;
            for (int j = 0; j <= i; j++)
                temp /= 10;
            for (int j = 0; j <= i; j++)
                temp *= 10;

            int temp2 = M - temp;
            for (int j = 0; j < i; j++)
                temp2 = temp2 / 10;

            sum += temp2;
        }

        if (M + sum == N)
            break;

        M++;
    }

    if (M == N)
        cout << 0;
    else
        cout << M;

    

    return 0;
}
