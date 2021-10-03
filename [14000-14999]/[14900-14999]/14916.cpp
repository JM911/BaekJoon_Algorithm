// 14916. 거스름돈
// S5

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 1 || N == 3)
    {
        cout << -1;
        return 0;
    }

    int coin2;
    int coin5;

    coin5 = N / 5;
    if ((N - 5 * coin5) % 2 != 0)
        coin5--;

    coin2 = (N - 5 * coin5) / 2;

    cout << coin5 + coin2;

    return 0;
}