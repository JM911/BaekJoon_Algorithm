// 11050. 이항 계수 1
// B1

#include <iostream>

using namespace std;

int Facto(int n)
{
    if(n == 1 || n == 0)
        return 1;
    else
        return n * Facto(n-1);
}

int main()
{
    int N, K;
    cin >> N >> K;

    int ans = Facto(N) / (Facto(K) * Facto(N-K));

    cout << ans;
}
