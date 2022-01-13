// 11051. 이항 계수 2
// S1

#include <bits/stdc++.h>
using namespace std;

int N, K;
int Comb[1010][1010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    int newK = min(K, N - K);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= min(i, newK); j++)
        {
            if(i==1 || i==j || j==0)
                Comb[i][j] = 1;
            else
                Comb[i][j] = (Comb[i - 1][j] + Comb[i - 1][j - 1]) % 10007;
        }
    }

    cout << Comb[N][newK];
}