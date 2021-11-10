// 7576. 토마토
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int box[1001][1001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    fastio;
    int N, M;
    cin >> M >> N;

    queue<pair<int, int>> q;
    int curTomatoes = 0;
    int noTomatoes = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if(box[i][j] == 1)
            {
                q.push(make_pair(i, j));
                curTomatoes++;
            }

            if(box[i][j] == -1)
            {
                noTomatoes++;
            }
        }
    }

    int allTomatoes = curTomatoes;

    int days = 0;
    int count = 0;
    int newTomatoes = 0;

    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(x<0 || y<0 || x>=N || y>=M)
                continue;
            
            if(box[x][y] == 0)
            {
                box[x][y] = 1;
                newTomatoes++;
                allTomatoes++;
                q.push(make_pair(x, y));
            }
        }

        count++;

        if(count == curTomatoes)
        {
            days++;
            curTomatoes = newTomatoes;
            count = 0;
            newTomatoes = 0;
        }
    }

    if(allTomatoes == N * M - noTomatoes)
        cout << days - 1;
    else
        cout << -1;
}