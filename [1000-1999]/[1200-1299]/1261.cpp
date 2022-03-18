// 1261. 알고스팟
// G4

#include <bits/stdc++.h>
using namespace std;

int N, M;
int maze[110][110];

int ans[110][110];
int dX[4] = {1, -1, 0, 0};
int dY[4] = {0, 0, 1, -1};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        string tmpStr;
        cin >> tmpStr;

        for (int j = 1; j <= N; j++)
        {
            maze[i][j] = tmpStr[j-1] - '0';
        }
    }

    fill(&ans[0][0], &ans[M][N + 1], 100001);

    queue<tuple<int, int, int>> q;      // x, y, ans
    q.push({1, 1, 0});
    ans[1][1] = 0;

    while (!q.empty())
    {
        int curX = get<0>(q.front());
        int curY = get<1>(q.front());
        int curAns = get<2>(q.front());
        q.pop();

        if(ans[curX][curY] != curAns)
            continue;

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dX[dir];
            int y = curY + dY[dir];

            if(x<1 || y<1 || x>M || y>N)
                continue;
            
            if(maze[x][y] == 0)
            {
                if(ans[x][y] <= ans[curX][curY])
                    continue;

                ans[x][y] = ans[curX][curY];
                q.push({x, y, ans[x][y]});
            }
            else
            {
                if(ans[x][y] <= ans[curX][curY] + 1)
                    continue;

                ans[x][y] = ans[curX][curY] + 1;
                q.push({x, y, ans[x][y]});
            }
        }
    }

    cout << ans[M][N];
}