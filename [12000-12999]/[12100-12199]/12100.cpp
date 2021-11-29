// 12100. 2048(Easy)
// G2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int game[30][30];
int gameOrigin[30][30];
int N;
int maxVal;

void DoLeft()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (game[i][k] == 0)
                {
                    game[i][k] = game[i][j];
                    game[i][j] = 0;
                    break;
                }
            }
        }

        for (int j = 0; j < N; j++)
        {
            if (game[i][j] != 0 && game[i][j] == game[i][j + 1])
            {
                game[i][j] *= 2;
                game[i][j + 1] = 0;
            }

            for (int k = 0; k < j; k++)
            {
                if (game[i][k] == 0)
                {
                    game[i][k] = game[i][j];
                    game[i][j] = 0;
                    break;
                }
            }
        }
    }
}

void DoRight()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N-1; j >=0; j--)
        {
            for (int k = N-1; k > j; k--)
            {
                if(game[i][k] == 0)
                {
                    game[i][k] = game[i][j];
                    game[i][j] = 0;
                    break;
                }
            }
        }

        for (int j = N-1; j >=0; j--)
        {
            if(j!=0 && game[i][j] != 0 && game[i][j] == game[i][j-1])
            {
                game[i][j] *= 2;
                game[i][j - 1] = 0;
            }
            
            for (int k = N-1; k > j; k--)
            {
                if(game[i][k] == 0)
                {
                    game[i][k] = game[i][j];
                    game[i][j] = 0;
                    break;
                }
            }
        }
    }
}

void DoUp()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if(game[k][i] == 0)
                {
                    game[k][i] = game[j][i];
                    game[j][i] = 0;
                    break;
                }
            }
        }

        for (int j = 0; j < N; j++)
        {
            if(game[j][i] != 0 && game[j][i] == game[j+1][i])
            {
                game[j][i] *= 2;
                game[j + 1][i] = 0;
            }

            for (int k = 0; k < j; k++)
            {
                if(game[k][i] == 0)
                {
                    game[k][i] = game[j][i];
                    game[j][i] = 0;
                    break;
                }
            }
        }
    }
}

void DoDown()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N-1; j >= 0; j--)
        {
            for (int k = N-1; k > j; k--)
            {
                if(game[k][i] == 0)
                {
                    game[k][i] = game[j][i];
                    game[j][i] = 0;
                    break;
                }
            }
        }

        for (int j = N-1; j >= 0; j--)
        {
            if(j!=0 && game[j][i] != 0 && game[j][i] == game[j-1][i])
            {
                game[j][i] *= 2;
                game[j - 1][i] = 0;
            }

            for (int k = N-1; k > j; k--)
            {
                if(game[k][i] == 0)
                {
                    game[k][i] = game[j][i];
                    game[j][i] = 0;
                    break;
                }
            }
        }
    }
}

void DoWhat(int dir)
{
    switch(dir)
    {
    case 0:
        DoLeft();
        break;
    case 1:
        DoUp();
        break;
    case 2:
        DoRight();
        break;
    case 3:
        DoDown();
        break;
    }
}

void Simul(int hash)
{
    int i_1 = hash % 4;

    hash /= 4;
    int i_2 = hash % 4;

    hash /= 4;
    int i_3 = hash % 4;
    
    hash /= 4;
    int i_4 = hash % 4;

    hash /= 4;
    int i_5 = hash % 4;

    DoWhat(i_1);
    DoWhat(i_2);
    DoWhat(i_3);
    DoWhat(i_4);
    DoWhat(i_5);
}

int main()
{
    fastio;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> game[i][j];
            gameOrigin[i][j] = game[i][j];
        }
    }

    for (int hash = 0; hash < 1024; hash++)
    {
        Simul(hash);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                maxVal = max(maxVal, game[i][j]);
                game[i][j] = gameOrigin[i][j];
            }
        }
    }

    cout << maxVal;
}