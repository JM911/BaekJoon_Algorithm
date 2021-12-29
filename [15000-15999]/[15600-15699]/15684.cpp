// 15684. 사다리 조작
// G4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M, H;
bool garo[35][15];
int ans = INT_MAX;
int prevIdx = 1;

int Sadari(int k)
{
    int tmp = k;

    for (int i = 1; i <= H; i++)
    {
        if(tmp>1 && garo[i][tmp-1] == true)
            tmp--;

        else if(garo[i][tmp] == true)
            tmp++;
    }

    return tmp;
}

void Simul(int len)
{

    bool CheckOk = true;

    for (int i = 1; i <= N; i++)
    {
        if(Sadari(i) != i)
        {
            CheckOk = false;
            break;
        }
    }

    if(CheckOk == true)
        ans = min(ans, len);

    if(len >= 3)
        return;

    for (int i = prevIdx; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if(garo[i][j] == true)
                continue;
            
            if(j>1 && garo[i][j-1] == true)
                continue;

            if(j<N-1 && garo[i][j+1] == true)
                continue;

            garo[i][j] = true;
            prevIdx = i;

            Simul(len + 1);

            garo[i][j] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        garo[a][b] = true;
    }

    Simul(0);

    if (ans == INT_MAX)
        cout << -1;

    else
        cout << ans;
}