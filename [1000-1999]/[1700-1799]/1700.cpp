// 1700. 멀티탭 스케줄링
// G1

#include <bits/stdc++.h>
using namespace std;

int N, K;
int ans;
int plug[110];
int tool[110];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> tool[i];
    }

    for (int t = 0; t < K; t++)
    {
        int nextTool = tool[t];

        bool isOK = false;
        for (int i = 0; i < N; i++)
        {
            if (plug[i] == 0)
            {
                plug[i] = nextTool;
                isOK = true;
                break;
            }

            if(plug[i] == nextTool)
            {
                isOK = true;
                break;
            }
        }

        if (isOK)
            continue;

        bool isReserved[110] = { false, };
        int count = 0;

        for (int i = t; i < K; i++)
        {
            for (int j = 0; j<N; j++)
            {
                if(plug[j] == tool[i])
                {
                    if(isReserved[j] == true)
                        break;

                    isReserved[j] = true;
                    count++;
                    break;
                }
            }

            if (count == N - 1)
                break;
        }

        for (int i = 0; i < N; i++)
        {
            if(isReserved[i] == false)
            {
                plug[i] = nextTool;
                ans++;
                break;
            }
        }
    }

    cout << ans;
}