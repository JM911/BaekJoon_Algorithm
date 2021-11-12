// 2146. 다리 만들기
// G3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

pair<int, bool> landMap[101][101];     // first: 섬 번호, second: 육지/바다 입력용
pair<int, int> bridgeTool[101][101];    // first: 출발 섬 번호, second: 다리 길이

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    fastio;
    int N;
    cin >> N;
    bool temp;

    stack<pair<int, int>> s1;    // 섬 번호 체크용
    queue<pair<int, int>> q2;    // 문제풀이용


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> temp;
            landMap[i][j] = make_pair(0, temp);

            if(temp)
            {
               s1.push(make_pair(i, j));
               q2.push(make_pair(i, j));
            }
        }
    }

    int islandNum = 0;

    while(!s1.empty())
    {
        int curX = s1.top().first;
        int curY = s1.top().second;
        s1.pop();

        if(landMap[curX][curY] == make_pair(0, true))
        {
            islandNum++;
            landMap[curX][curY].first = islandNum;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(x<0 || y<0 || x>=N || y>=N)
                continue;
            if (landMap[x][y] == make_pair(0, true))
            {
                landMap[x][y].first = landMap[curX][curY].first;
                s1.push(make_pair(x, y));
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bridgeTool[i][j].first = landMap[i][j].first;
        }
    }

    vector<int> ans;

    while(!q2.empty())
    {
        int curX = q2.front().first;
        int curY = q2.front().second;
        q2.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int x = curX + dx[dir];
            int y = curY + dy[dir];

            if(x<0 || y<0 || x>=N || y>=N)
                continue;
            
            if(bridgeTool[x][y].second != 0 && bridgeTool[x][y].first != bridgeTool[curX][curY].first)
            {
                ans.push_back(bridgeTool[x][y].second + bridgeTool[curX][curY].second);
            }

            if(landMap[x][y].second == false && bridgeTool[x][y].second == 0) 
            {
                bridgeTool[x][y].first = bridgeTool[curX][curY].first;
                bridgeTool[x][y].second = bridgeTool[curX][curY].second + 1;
                q2.push(make_pair(x, y));
            }
        }
    }

    int realAns = INT_MAX;

    for(int a : ans)
    {
        realAns = min(realAns, a);
    }

    cout << realAns;
}
