// 16985. Maaaaaaaaaze
// G3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool pan[10][10][10];
bool rotatedPan[5][10][10][10];
bool maze[10][10][10];
int ans = INT_MAX;
bool isVisitedFloor[10];

int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};

int SolveMaze()
{
    if(maze[0][0][0] == false)
        return -1;

    int arr[5][5][5];
    fill(&arr[0][0][0], &arr[4][4][5], 0);

    queue<tuple<int, int, int>> q;
    arr[0][0][0] = 1;
    q.push({0, 0, 0});

    while(!q.empty())
    {
        int curZ = get<0>(q.front());
        int curX = get<1>(q.front());
        int curY = get<2>(q.front());
        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int z = curZ + dz[dir];
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(z<0 || x<0 || y<0 || z>=5 || x>=5 || y>=5)
                continue;
            
            if(arr[z][x][y] != 0 || maze[z][x][y] == false)
                continue;

            arr[z][x][y] = arr[curZ][curX][curY] + 1;
            q.push({z, x, y});
        }
    }

    return arr[4][4][4] - 1;
}

void RotatePan()
{
    for (int idx = 0; idx < 5; idx++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                rotatedPan[0][idx][i][j] = pan[idx][i][j];
            }
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                rotatedPan[1][idx][i][j] = pan[idx][j][4 - i];
            }
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                rotatedPan[2][idx][i][j] = pan[idx][4 - i][4 - j];
            }
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                rotatedPan[3][idx][i][j] = pan[idx][4 - j][i];
            }
        }
    }
}

void MakeMaze(int floor)
{
    if(floor == 5)
    {
        int tmp = SolveMaze();
        if (tmp != -1)
            ans = min(ans, tmp);

        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if(isVisitedFloor[i])
            continue;
        
        isVisitedFloor[i] = true;

        for (int rot = 0; rot < 4; rot++)
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    maze[floor][j][k] = rotatedPan[rot][i][j][k];
                }
            }

            MakeMaze(floor + 1);
        }

        isVisitedFloor[i] = false;
    }
}

int main()
{
    fastio;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> pan[i][j][k];
                // cin >> maze[i][j][k];
            }
        }
    }

    RotatePan();
    MakeMaze(0);

    if(ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}