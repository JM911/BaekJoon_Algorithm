// 21940. 가운데에서 만나기
// G4

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 210

int N, M;
int T[MAX_NUM][MAX_NUM];

int K;
int C[MAX_NUM];

int minLen = INT_MAX;
vector<int> ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    fill(&T[0][0], &T[N + 1][N], 9999);

    while (M--)
    {
        int a, b;
        cin >> a >> b;
        cin >> T[a][b];
    }

    cin >> K;

    for (int i = 1; i <= K; i++)
    {
        cin >> C[i];
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if(i == j || T[i][j] <= T[i][k] + T[k][j])
                    continue;

                T[i][j] = T[i][k] + T[k][j];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int tmpMax = 0;

        for (int j = 1; j <= K; j++)
        {
            if(C[j] == i)
                continue;

            tmpMax = max(tmpMax, T[C[j]][i] + T[i][C[j]]);
        }

        if(minLen == tmpMax)
            ans.push_back(i);
        else if(minLen > tmpMax)
        {
            minLen = tmpMax;

            ans.clear();
            ans.push_back(i);
        }
    }

    for(auto a : ans)
    {
        cout << a << ' ';
    }
}