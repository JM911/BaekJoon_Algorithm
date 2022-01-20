// 18869. 멀티버스 II
// G5

#include "bits/stdc++.h"
using namespace std;

int M, N;
int planet[110][10010];
int tmp[10010];
int tmp2[10010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> planet[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tmp[j] = planet[i][j];
        }

        sort(tmp, tmp + N);

        int count = 0;
        tmp2[count++] = tmp[0];

        for (int j = 1; j < N; j++)
        {
            if(tmp[j] != tmp[j-1])
                tmp2[count++] = tmp[j];
        }
        for (int j = 0; j < N; j++)
        {
            planet[i][j] = lower_bound(tmp2, tmp2 + count, planet[i][j]) - tmp2;
        }
    }

    int ans = 0;

    for (int i = 0; i < M-1; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            bool isBalanced = true;
            for (int k = 0; k < N; k++)
            {
                if (planet[i][k] != planet[j][k])
                {
                    isBalanced = false;
                    break;
                }
            }

            if(isBalanced)
                ans++;
        }
    }

    cout << ans;
}