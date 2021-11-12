// 5427. 불
// G4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char buildingMap[1001][1001];
int fire[1001][1001];
int sang[1001][1001];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    fastio;
    int T;
    cin >> T;

    while(T--)
    {
        int w, h;
        cin >> w >> h;

        queue<pair<int, int>> qf;
        queue<pair<int, int>> qs;

        for (int i = 0; i < h; i++)
        {
            string str;
            cin >> str;

            for (int j = 0; j < w; j++)
            {
                buildingMap[i][j] = str[j];

                if(str[j] == '*')
                {
                    qf.push({i, j});
                    fire[i][j] = 1;
                }

                if(str[j] == '@')
                {
                    qs.push({i, j});
                    sang[i][j] = 1;
                }
            }
        }

        while(!qf.empty())
        {
            int curX = qf.front().first;
            int curY = qf.front().second;
            qf.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int x = curX + dx[dir];
                int y = curY + dy[dir];

                if(x<0 || y<0 || x>=h || y>=w)
                    continue;
                
                if(buildingMap[x][y] != '#' && fire[x][y] == 0)
                {
                    fire[x][y] = fire[curX][curY] + 1;
                    qf.push({x, y});
                }
            }
        }

        while(!qs.empty())
        {
            int curX = qs.front().first;
            int curY = qs.front().second;
            qs.pop();
            
            for (int dir = 0; dir < 4; dir++)
            {
                int x = curX + dx[dir];
                int y = curY + dy[dir];

                if(x<0 || y<0 || x>=h || y>=w)
                    continue;

                if(buildingMap[x][y] != '#' && sang[x][y] == 0)
                {
                    sang[x][y] = sang[curX][curY] + 1;
                    qs.push({x, y});
                }
            }
        }

        // for (int i = 0; i < h; i++)
        // {
        //     for (int j = 0; j < w; j++)
        //     {
        //         cout << fire[i][j];
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // for (int i = 0; i < h; i++)
        // {
        //     for (int j = 0; j < w; j++)
        //     {
        //         cout << sang[i][j];
        //     }
        //     cout << '\n';
        // }        
        // cout << '\n';
        

        int ans = INT_MAX;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
                {
                    if (buildingMap[i][j] != '#' && sang[i][j] != 0 && sang[i][j] < fire[i][j])
                    {
                        ans = min(ans, sang[i][j]);
                    }

                    if (sang[i][j] != 0 && fire[i][j] == 0)
                    {
                        ans = min(ans, sang[i][j]);
                    }
                }
            }
        }

        if(ans == INT_MAX)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << ans << '\n';

        fill(&fire[0][0], &fire[h - 1][w], 0);
        fill(&sang[0][0], &sang[h - 1][w], 0);
    }
}
