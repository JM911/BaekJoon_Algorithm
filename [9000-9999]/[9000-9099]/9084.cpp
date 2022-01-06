// 9084. 동전
// G5

#include <bits/stdc++.h>
using namespace std;

int T, N, M;
vector<int> coin;
int combNum[10010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--)
    {
        fill(combNum, combNum + 10000, 0);
        combNum[0] = 1;

        cin >> N;

        coin.clear();

        for (int i = 0; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            coin.push_back(tmp);
        }

        cin >> M;

        for(int j : coin)
        {
            for (int i = 1; i <= M; i++)
            {
                if(i-j>=0)
                    combNum[i] += combNum[i - j];
            }
        }

        cout << combNum[M] << '\n';
    }
} 