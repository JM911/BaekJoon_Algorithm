// 7562. 나이트의 이동
// S2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int pan[301][301];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, 2, -2, 2, -2, 1, -1};

int main()
{
    fastio;
    int T;
    cin >> T;

    while(T--)
    {
        int I;
        cin >> I;

        fill(&pan[0][0], &pan[I - 1][I], -1);
        queue<pair<int, int>> q;

        int befX, befY;
        int tarX, tarY;

        cin >> befX >> befY;
        cin >> tarX >> tarY;

        pan[befX][befY] = 0;
        q.push({befX, befY});
        int ans;

        while(!q.empty())
        {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int x = curX + dx[dir];
                int y = curY + dy[dir];

                if(x<0 || y<0 || x>=I || y>=I)
                    continue;
                if(pan[x][y] != -1)
                    continue;

                pan[x][y] = pan[curX][curY] + 1;
                q.push({x, y});
            }

            if(curX == tarX && curY == tarY)
            {
                ans = pan[curX][curY];
                break;
            }
        }

        cout << ans << '\n';
    }
}
