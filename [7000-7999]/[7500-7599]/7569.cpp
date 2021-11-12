// 7569. 토마토
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int box[101][101][101];
//bool isVisited[101][101][101];

int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    fastio;
    int M, N, H;
    cin >> M >> N >> H;

    int noTomatoes = 0;
    int allTomatoes = 0;
    queue<tuple<int, int, int>> q;

    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> box[k][i][j];
                
                if(box[k][i][j] == 1)
                {
                    q.push(make_tuple(k, i, j));
                    //isVisited[k][i][j] = true;
                    allTomatoes++;
                }
                
                else if(box[k][i][j] == -1)
                    noTomatoes++;
            }
        }
    }

    int days = 0;

    while(!q.empty())
    {
        int curZ = get<0>(q.front());
        int curX = get<1>(q.front());
        int curY = get<2>(q.front());
        days = max(days, box[curZ][curX][curY]);
        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int z = curZ + dz[dir];
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(z<0 || x<0 || y<0 || z>=H || x>=N || y>=M)
                continue;

            if (box[z][x][y] == 0)
            {
                box[z][x][y] = box[curZ][curX][curY] + 1;
                allTomatoes++;
                q.push({z, x, y});
            }
        }
    }

    // for (int k = 0; k < H; k++)
    // {
    //     for (int i = 0; i < M; i++)
    //     {
    //         for (int j = 0; j < N; j++)
    //         {
    //             cout << box[k][i][j] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    if(allTomatoes == M * N * H - noTomatoes)
        cout << days - 1;

    else
        cout << -1;
}
