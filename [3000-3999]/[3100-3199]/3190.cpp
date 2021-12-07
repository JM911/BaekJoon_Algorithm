// 3190. 뱀
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, K, L;
pair<int, int> apple[110];
pair<int, char> movePath[110];
int board[110][110];       // 0: 빈 공간, 1: 뱀, 2: 사과
int timeCount;
pair<int, int> snakeHead;
int dir = 1;

int main()
{
    fastio;
    cin >> N >> K;
    
    for (int i = 0; i < K; i++)
    {
        int tmpX, tmpY;
        cin >> tmpX >> tmpY;
        apple[i] = {tmpX-1, tmpY-1};
        board[apple[i].first][apple[i].second] = 2;
    }

    cin >> L;

    for (int i = 0; i < L; i++)
    {
        cin >> movePath[i].first >> movePath[i].second;
    }

    queue<pair<int, int>> snakeBody;
    board[0][0] = 1;
    snakeBody.push({0, 0});
    snakeHead = {0, 0};
    int turn = 0;

    while(true)
    {
        timeCount++;

        int x = snakeHead.first;
        int y = snakeHead.second;

        switch(dir)
        {
        case 0:
            x--;
            break;
        case 1:
            y++;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        }

        if(x<0 || y<0 || x>=N || y>=N || board[x][y] == 1)
            break;

        if(board[x][y] != 2)
        {
            board[snakeBody.front().first][snakeBody.front().second] = 0;
            snakeBody.pop();
        }

        board[x][y] = 1;
        snakeBody.push({x, y});
        snakeHead = {x, y};

        if(turn < L && timeCount == movePath[turn].first)
        {
            char changeDir = movePath[turn].second;
            if(changeDir == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
            turn++;
        }
    }

    cout << timeCount;

    return 0;
}