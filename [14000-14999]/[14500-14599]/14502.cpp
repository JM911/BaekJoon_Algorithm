// 14502. 연구소
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
int labMap[10][10];
int tempLabMap[10][10];
queue<pair<int, int>> virusQ;
vector<pair<int, int>> virusIdx;

pair<int, int> blankRegion[80];
int blankCount;
vector<int> pickIdx;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;

int main()
{
    fastio;
    cin >> N >> M;

    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> labMap[i][j];
            if(labMap[i][j] == 2)
                virusIdx.push_back({i, j});

            if(labMap[i][j] == 0)
                blankRegion[blankCount++] = {i, j};
        }
    }

    for (int i = 0; i<blankCount; i++)
    {
        pickIdx.push_back(i < 3 ? 0 : 1);
    }

    do{
        for (int i = 0; i < virusIdx.size(); i++)
            virusQ.push({virusIdx[i].first, virusIdx[i].second});

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                tempLabMap[i][j] = labMap[i][j];
            }
        }

        for (int i = 0; i < blankCount; i++)
        {
            if (pickIdx[i] == 0)
            {
                int x = blankRegion[i].first;
                int y = blankRegion[i].second;

                tempLabMap[x][y] = 1;
            }
        }

        int tempBlank = blankCount - 3;

        while(!virusQ.empty())
        {
            int curX = virusQ.front().first;
            int curY = virusQ.front().second;
            virusQ.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int x = curX + dx[dir];
                int y = curY + dy[dir];

                if(x<0 || y<0 || x>=N || y>=M)
                    continue;
                
                if(tempLabMap[x][y] == 0)
                {
                    tempBlank--;
                    tempLabMap[x][y] = 2;
                    virusQ.push({x, y});
                }
            }
        }

        ans = max(ans, tempBlank);
    } while (next_permutation(pickIdx.begin(), pickIdx.end()));

    cout << ans;
}