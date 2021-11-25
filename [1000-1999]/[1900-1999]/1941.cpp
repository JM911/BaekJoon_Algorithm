// 1941. 소문난 칠공주
// G3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char students[7][7];
pair<int, int> sevenGirlsIdx[10];
int numS, ans;
int prevHash = -1;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isVisited[7][7];

bool isOne(int len)
{
    int tempLen = 0;
    stack<pair<int, int>> s;
    bool check;

    s.push({sevenGirlsIdx[0].first, sevenGirlsIdx[0].second});
    isVisited[sevenGirlsIdx[0].first][sevenGirlsIdx[0].second] = true;
    tempLen++;

    while(!s.empty())
    {
        int curX = s.top().first;
        int curY = s.top().second;
        s.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(x<0 || y<0 || x>=5 || y>=5)
                continue;
            
            if(isVisited[x][y] == true)
                continue;

            for (int i = 0; i < len; i++)
            {
                if(x==sevenGirlsIdx[i].first && y==sevenGirlsIdx[i].second)
                {
                    s.push({x, y});
                    isVisited[x][y] = true;
                    tempLen++;
                }
            }
        }
    }

    if(tempLen == len)
        check = true;
    else
        check = false;

    fill(&isVisited[0][0], &isVisited[4][5], false);
    return check;
}

void PickSeven(int len)
{
    if(len == 7)
    {
        if(isOne(len) && numS>3)
            ans++;
        return;
    }

    for (int i = prevHash + 1; i < 25; i++)
    {
        int x = i / 5;
        int y = i % 5;

        if(students[x][y] == 'S')
            numS++;

        sevenGirlsIdx[len] = {x, y};

        prevHash = x * 5 + y;
        PickSeven(len + 1);

        if(students[x][y] == 'S')
            numS--;
    }
}

int main()
{
    fastio;
    for (int i = 0; i < 5; i++)
    {
        string strTemp;
        cin >> strTemp;

        for (int j = 0; j < 5; j++)
        {
            students[i][j] = strTemp[j];
        }
    }

    PickSeven(0);

    cout << ans;
}