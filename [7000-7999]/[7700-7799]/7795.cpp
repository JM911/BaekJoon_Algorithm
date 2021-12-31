// 7795. 먹을 것인가 먹힐 것인가
// S3

#include "bits/stdc++.h"
using namespace std;

int T, N, M;
int Aset[20010];
int Bset[20010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--)
    {
        cin >> N >> M;

        for (int i = 0; i < N; i++)
        {
            cin >> Aset[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> Bset[i];
        }

        sort(Aset, Aset + N);
        sort(Bset, Bset + M);

        int count = 0;
        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            while(count<M)
            {
                if(Aset[i] <= Bset[count])
                    break;
                count++;
            }
            ans += count;
        }

        cout << ans << '\n';
    }
}