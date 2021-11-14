// 1600. 말이 되고픈 원숭이
// G4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool pan[201][201];
int go[31][201][201];

int dxKnight[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dyKnight[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    fastio;
    int K, W, H;
    cin >> K >> W >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> pan[i][j];
        }
    }

    fill(&go[0][0][0], &go[30][H][W], -1);
    queue<tuple<int, int, int>> q;

    go[0][0][0] = 0;
    q.push({0, 0, 0});

    while(!q.empty())
    {
        int moveCount = get<0>(q.front());
        int curX = get<1>(q.front());
        int curY = get<2>(q.front());
        q.pop();

        if(moveCount < K)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int x = curX + dxKnight[dir];
                int y = curY + dyKnight[dir];

                if(x<0 || y<0 || x>=H || y>=W)
                    continue;
                
                if(pan[x][y] == false && go[moveCount + 1][x][y] == -1)
                {
                    go[moveCount + 1][x][y] = go[moveCount][curX][curY] + 1;
                    q.push({moveCount + 1, x, y});
                }
            }
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(x<0 || y<0 || x>=H || y>=W)
                continue;
            
            if(pan[x][y] == false && go[moveCount][x][y] == -1)
            {
                go[moveCount][x][y] = go[moveCount][curX][curY] + 1;
                q.push({moveCount, x, y});
            }
        }
    }

    vector<int> v;

    for (int i = 0; i < 31; i++)
    {
        v.push_back(go[i][H - 1][W - 1]);
    }

    sort(v.begin(), v.end());

    int ans = -1;

    for (int i = 0; i < 31; i++)
    {
        if(v[i] != -1)
        {
            ans = v[i];
            break;
        }
    }

    cout << ans;
}
