// 9663. N-Queen
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, ans;
int arr[20];
int canBe[20][20];

void AddQueen(int x, int y)
{
    canBe[x][y]++;
    for (int i = 1; i <= N; i++)
    {
        if(i != x)
            canBe[i][y]++;
        if(i != y)
            canBe[x][i]++;
        
        if(x-i>=1)
        {
            if(y-i>=1)
                canBe[x - i][y - i]++;
            if(y+i<=N)
                canBe[x - i][y + i]++;
        }

        if(x+i<=N)
        {
            if(y-i>=1)
                canBe[x + i][y - i]++;
            if(y+i<=N)
                canBe[x + i][y + i]++;
        }
    }
}

void DelQueen(int x, int y)
{
    canBe[x][y]--;
    for (int i = 1; i <= N; i++)
    {
        if(i != x)
            canBe[i][y]--;
        if(i != y)
            canBe[x][i]--;
        
        if(x-i>=1)
        {
            if(y-i>=1)
                canBe[x - i][y - i]--;
            if(y+i<=N)
                canBe[x - i][y + i]--;
        }

        if(x+i<=N)
        {
            if(y-i>=1)
                canBe[x + i][y - i]--;
            if(y+i<=N)
                canBe[x + i][y + i]--;
        }
    }
}

void Nqueen(int len)
{
    if(len == N+1)
    {
        ans++;
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if(canBe[len][i] == 0)
        {
            arr[len] = i;
            AddQueen(len, i);
            Nqueen(len + 1);
            DelQueen(len, i);
        }
    }
}

int main()
{
    fastio;
    cin >> N;

    Nqueen(1);

    cout << ans;
}
