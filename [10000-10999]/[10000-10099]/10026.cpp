// 10026. 적록색약
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char colorMap[101][101];
bool isVisited[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    fastio;
    int N;
    cin >> N;

    stack<pair<int, int>> s;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < N; j++)
        {
            colorMap[i][j] = str[j];
        }
    }

    int blockNum = 0;
    int blockNum2 = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(isVisited[i][j] == false)
            {
               blockNum++;
               isVisited[i][j] = true;
               s.push(make_pair(i, j));
            }

            while(!s.empty())
            {
                int curX = s.top().first;
                int curY = s.top().second;
                s.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int x = curX + dx[dir];
                    int y = curY + dy[dir];

                    if (x < 0 || y < 0 || x >= N || y >= N)
                       continue;
                    
                    if(isVisited[x][y] == false && colorMap[x][y] ==  colorMap[curX][curY])
                    {
                        isVisited[x][y] = true;
                        s.push(make_pair(x, y));
                    }
                }
            }
        }
    }

    fill(isVisited[0], &isVisited[N - 1][N], 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(colorMap[i][j] == 'G')
                colorMap[i][j] = 'R';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (isVisited[i][j] == false)
            {
                blockNum2++;
                isVisited[i][j] = true;
                s.push(make_pair(i, j));
            }

            while (!s.empty())
            {
                int curX = s.top().first;
                int curY = s.top().second;
                s.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int x = curX + dx[dir];
                    int y = curY + dy[dir];

                    if (x < 0 || y < 0 || x >= N || y >= N)
                        continue;

                    if (isVisited[x][y] == false && colorMap[x][y] == colorMap[curX][curY])
                    {
                        isVisited[x][y] = true;
                        s.push(make_pair(x, y));
                    }
                }
            }
        }
    }

    cout << blockNum << ' ' << blockNum2;
}
