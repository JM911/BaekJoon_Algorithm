// 2667. 단지번호붙이기
// S1

#include <bits/stdc++.h>
using namespace std;

int N;
int myBoard[30][30];
bool vis[30][30];

int dX[4] = {1, -1, 0, 0};
int dY[4] = {0, 0, 1, -1};
vector<int> vecAns;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < N; j++)
        {
            myBoard[i][j] = tmp[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(vis[i][j] == true || myBoard[i][j] == 0)
                continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = true;
            int tmpCnt = 1;

            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int x = cur.first + dX[dir];
                    int y = cur.second + dY[dir];

                    if(x<0 || y<0 || x>=N || y>=N)
                        continue;
                    
                    if(vis[x][y] == true || myBoard[x][y] == 0)
                        continue;

                    vis[x][y] = true;
                    tmpCnt++;
                    //myBoard[x][y] = myBoard[cur.first][cur.second];
                    q.push({x, y});
                }
            }

            vecAns.push_back(tmpCnt);
        }
    }

    sort(vecAns.begin(), vecAns.end());

    cout << vecAns.size() << '\n';
    for(auto a : vecAns)
    {
        cout << a << '\n';
    }
}