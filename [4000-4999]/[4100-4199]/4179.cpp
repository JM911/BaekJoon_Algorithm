// 4179. 불!
// G4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char maze[1001][1001];
int fire[1001][1001];
int walk[1001][1001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    fastio;
    int R, C;
    cin >> R >> C;

    queue<pair<int, int>> fq;
    queue<pair<int, int>> jq;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 'F')
                fq.push(make_pair(i, j));
            if(maze[i][j] == 'J')
                jq.push(make_pair(i, j));
        }
    }

    while (!fq.empty())
    {
        int curX = fq.front().first;
        int curY = fq.front().second;
        fq.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if (x < 0 || y < 0 || x >= R || y >= C)
                continue;

            if (maze[x][y] == '.' && fire[x][y] == 0)
            {
                fire[x][y] = fire[curX][curY] + 1;
                fq.push(make_pair(x, y));
            }
        }
    }

    int escapeMin = INT_MAX;

    if (jq.front().first == 0 || jq.front().second == 0 || jq.front().first == R-1 || jq.front().second == C-1)
        escapeMin = 0;

    else
    {
        while(!jq.empty())
        {
            int curX = jq.front().first;
            int curY = jq.front().second;
            jq.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int x = curX + dx[dir];
                int y = curY + dy[dir];

                if(x<0 || y<0 || x>=R || y>=C)
                    continue;

                if(maze[x][y] == '.' && walk[x][y] == 0)
                {
                    walk[x][y] = walk[curX][curY] + 1;
                    jq.push(make_pair(x, y));

                    if(x==0 || y==0 || x==R-1 || y==C-1)
                    {
                        if(walk[x][y] < fire[x][y] || fire[x][y] == 0)
                        {
                            escapeMin = min(escapeMin, walk[x][y]);
                        }
                    }
                }
            }
        }
    }

    if(escapeMin == INT_MAX)
        cout << "IMPOSSIBLE";
    else
        cout << escapeMin + 1;
}