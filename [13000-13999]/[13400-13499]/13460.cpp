// 13460. 구슬 탈출 2
// G1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
char board[12][12];
pair<int, int> redBall;
pair<int, int> blueBall;
bool isRedOut;
bool isBlueOut;
int minTimes = 11;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Leaning(int dir);
void LeaningRed(int dir);
void LeaningBlue(int dir);

void Solving(int times)
{
    if(isBlueOut)
    {
        isBlueOut = false;
        isRedOut = false;
        return;
    }

    else if(isRedOut)
    {
        minTimes = min(minTimes, times);
        isRedOut = false;
        return;
    }

    else if(times == 10)
    {
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        pair<int, int> tmpRedBall = redBall;
        pair<int, int> tmpBlueBall = blueBall;

        Leaning(dir);
        Solving(times + 1);

        board[redBall.first][redBall.second] = '.';
        board[tmpRedBall.first][tmpRedBall.second] = 'R';
        redBall = tmpRedBall;

        board[blueBall.first][blueBall.second] = '.';
        board[tmpBlueBall.first][tmpBlueBall.second] = 'B';
        blueBall = tmpBlueBall;
    }
}

void Leaning(int dir)
{
    LeaningRed(dir);
    LeaningBlue(dir);
    LeaningRed(dir);
}

void LeaningRed(int dir)
{
    int x, y;

    x = redBall.first;
    y = redBall.second;

    while(true)
        {
            x += dx[dir];
            y += dy[dir];

            if(x<0 || y<0 || x>=N || y>=M)
            {
                x -= dx[dir];
                y -= dy[dir];
                break;
            }
            else if(board[x][y] == 'O')
            {
                isRedOut = true;
                break;
            }
            else if(board[x][y] != '.')
            {
                x -= dx[dir];
                y -= dy[dir];
                break;
            }
        }

    board[redBall.first][redBall.second] = '.';
    if(!isRedOut)
    {
        board[x][y] = 'R';
        redBall = {x, y};
    }
}

void LeaningBlue(int dir)
{
    int x, y;

    x = blueBall.first;
    y = blueBall.second;

    while(true)
        {
            x += dx[dir];
            y += dy[dir];

            if(x<0 || y<0 || x>=N || y>=M)
            {
                x -= dx[dir];
                y -= dy[dir];
                break;
            }
            else if(board[x][y] == 'O')
            {
                isBlueOut = true;
                break;
            }
            else if(board[x][y] != '.')
            {
                x -= dx[dir];
                y -= dy[dir];
                break;
            }
        }

    board[blueBall.first][blueBall.second] = '.';
    if(!isBlueOut)
    {
        board[x][y] = 'B';
        blueBall = {x, y};
    }
}

int main()
{
    fastio;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string tmpStr;
        cin >> tmpStr;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = tmpStr[j];
            if(board[i][j] == 'R')
                redBall = {i, j};
            if(board[i][j] == 'B')
                blueBall = {i, j};
        }
    }

    Solving(0);

    if(minTimes == 11)
        cout << -1;
    else
        cout << minTimes;
}