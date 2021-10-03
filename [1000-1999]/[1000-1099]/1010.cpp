// 1010. 다리 놓기
// S5

#include <iostream>
using namespace std;

long long Combi(int r, int n)
{
    long long ans = 1;

    for (int i = 1; i <= r; i++)
    {
        ans *= n - i + 1;
        ans /= i;
    }

    return ans;
}

int main()
{
    int T, N, M;
    cin >> T;

    while (T > 0)
    {
        cin >> N >> M;

        cout << Combi(N, M) << endl;

        T--;
    }

    return 0;
}