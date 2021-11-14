// 2573. 빙산
// G4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int glacier[301][301];
bool isVisited[301][301];
bool isDone = false;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isOne(queue<pair<int, int>>* q, int N, int M)
{
    if(q->empty())
    {
        isDone = true;
        return false;
    }

    isVisited[q->front().first][q->front().second] = true;

    while(!q->empty())
    {
        int curX = q->front().first;
        int curY = q->front().second;
        q->pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(x<0 || y<0 || x>=N || y>=M)
                continue;

            if(glacier[x][y]>0 && isVisited[x][y] == false)
            {
                isVisited[x][y] = true;
                q->push({x, y});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(glacier[i][j] > 0 && isVisited[i][j] == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    fastio;
    int N, M;
    cin >> N >> M;

    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> glacier[i][j];

            if(glacier[i][j] == 0)
            {
                glacier[i][j] = -5;
            }

            if(glacier[i][j] > 0)
            {
                if(!q.empty())
                    q.pop();
                
                q.push({i, j});
            }
        }
    }

    int year = 0;

    while(isOne(&q, N, M))
    {
        year++;
        for (int i = 0; i<N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(glacier[i][j] > 0)
                {
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int x = i + dx[dir];
                        int y = j + dy[dir];

                        if(x<0 || y<0 || x>=N || y>=M)
                            continue;
                        
                        if(glacier[x][y] == -5)
                            glacier[i][j]--;
                    }
                }
            }
        }

        for (int i = 0; i<N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(glacier[i][j] != -5 && glacier[i][j] <= 0)
                {
                    glacier[i][j] = -5;
                }

                if(glacier[i][j] > 0)
                {
                    if(!q.empty())
                        q.pop();
                    
                    q.push({i, j});
                }
            }
        }

        fill(&isVisited[0][0], &isVisited[N - 1][M], false);
    }

    if(isDone)
        cout << 0;
    else
        cout << year;
}
