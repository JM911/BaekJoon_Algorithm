// 11559. Puyo Puyo
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char gameBoard[15][10];
bool isFour[15][10];
bool isVisited[15][10];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool SearchFour()
{
    fill(&isVisited[0][0], &isVisited[14][10], false);
    bool searched = false;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if(gameBoard[i][j] == '.' || isVisited[i][j] == true)
                continue;

            stack<pair<int, int>> s;
            queue<pair<int, int>> q;
            int tempPuyoNum = 1;
            s.push({i, j});
            isVisited[i][j] = true;

            while(!s.empty())
            {
                int curX = s.top().first;
                int curY = s.top().second;
                s.pop();
                q.push({curX, curY});
                char curColor = gameBoard[curX][curY];

                for (int dir = 0; dir < 4; dir++)
                {
                    int x = curX + dx[dir];
                    int y = curY + dy[dir];
                    
                    if(x<0 || y<0 || x>=12 || y>=6)
                        continue;
                    
                    if(isVisited[x][y] == true)
                        continue;
                    
                    if(gameBoard[x][y] == curColor)
                    {
                        isVisited[x][y] = true;
                        tempPuyoNum++;
                        s.push({x, y});
                        q.push({x, y});
                    }
                }
            }

            if(tempPuyoNum >= 4)
            {
                searched = true;
                
                while(!q.empty())
                {
                    isFour[q.front().first][q.front().second] = true;
                    q.pop();
                }
            }
        }
    }

    return searched;
}

void Boom()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if(isFour[i][j] == true)
            {
                gameBoard[i][j] = '.';
            }
        }
    }

    fill(&isFour[0][0], &isFour[14][10], false);
}

void Fall()
{
    for (int j = 0; j < 6; j++)
    {
        int lastSpace = 11;
        
        while(lastSpace>=0 && gameBoard[lastSpace][j] != '.')
        {
            lastSpace--;
        }

        for (int i = lastSpace; i >= 0; i--)
        {
            if(gameBoard[i][j] == '.')
                continue;
            else
            {
                gameBoard[lastSpace][j] = gameBoard[i][j];
                gameBoard[i][j] = '.';
                lastSpace--;
            }
        }
    }
}

int main()
{
    fastio;

    for (int i = 0; i < 12; i++)
    {
        string tempStr;
        cin >> tempStr;
        for (int j = 0; j < 6; j++)
        {
            gameBoard[i][j] = tempStr[j];
        }
    }

    int ans = 0;

    while(SearchFour())
    {
        ans++;
        Boom();
        Fall();
    }

    cout << ans;
}