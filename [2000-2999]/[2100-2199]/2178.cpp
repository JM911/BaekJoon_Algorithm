// 2178. 미로 탐색
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool maze[101][101];
bool isVisited[101][101];
int dist[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < m; j++)
        {
            maze[i][j] = temp[j] - '0';
        }
    }

    queue<pair<int, int>> q;

    isVisited[0][0] = true;
    dist[0][0] = 1;
    q.push(make_pair(0, 0));
    
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(x<0 || y<0 || x>=n || y>=m)
                continue;
            
            if(maze[x][y] == true && isVisited[x][y] == false)
            {
                isVisited[x][y] = true;
                dist[x][y] = dist[curX][curY] + 1;
                q.push(make_pair(x, y));
            }
        }
    }

    cout << dist[n - 1][m - 1];
}