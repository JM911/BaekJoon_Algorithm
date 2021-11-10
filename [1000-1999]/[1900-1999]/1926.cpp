// 1926. 그림
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool paint[501][501];
bool isVisited[501][501];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> paint[i][j];
        }
    }

    queue<pair<int, int>> q;
    int curX = 0;
    int curY = 0;
    int x, y;


    int ans = 0;
    int max = 0;

    for (int i = 0; i < n;  i++)
    {
        for (int j = 0; j < m; j++)
        {
            int area = 0;

            if(paint[i][j] == true && isVisited[i][j]==false)
            {
                ans++;
                q.push(make_pair(i, j));
                isVisited[i][j] = true;
                area++;
            }

            while(!q.empty())
            {
                curX = q.front().first;
                curY = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    x = curX + dx[dir];
                    y = curY + dy[dir];

                    if(x<0 || y<0 || x>=n || y>=m)
                        continue;
                    if(paint[x][y] == true && isVisited[x][y] == false)
                    {
                        isVisited[x][y] = true;
                        q.push(make_pair(x, y));
                        area++;
                    }
                }
            }

            if(max < area)
                max = area;
        }
    }

    cout << ans << '\n'
         << max;
}