// 15685. 드래곤 커브
// G4

#include <bits/stdc++.h>
using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
pair<int, int> arrStartPt[25];
vector<int> vecDir[25];
int arrGen[25];

bool bGrid[120][120];
int ans;

int RotateOnce(int dir)
{
    dir++;
    dir %= 4;
    return dir;
}

void CurveGenPlus(vector<int>& vecDir, int gen)
{
    for (int g = 0; g < gen; g++)
    {
        int vecSize = vecDir.size();
        for (int i = 0; i < vecSize; i++)
        {
            int prevDir = vecDir[vecSize - i - 1];
            int nextDir = RotateOnce(prevDir);
            vecDir.push_back(nextDir);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmpDir;
        cin >> arrStartPt[i].first >> arrStartPt[i].second;
        cin >> tmpDir;
        vecDir[i].push_back(tmpDir);
        cin >> arrGen[i];
    }

    for (int i = 0; i < N; i++)
    {
        CurveGenPlus(vecDir[i], arrGen[i]);

        int x = arrStartPt[i].first;
        int y = arrStartPt[i].second;
        bGrid[x][y] = true;

        for (int j = 0; j < vecDir[i].size(); j++)
        {
            x += dx[vecDir[i][j]];
            y += dy[vecDir[i][j]];
            bGrid[x][y] = true;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if(!bGrid[i][j])
                continue;
            if(!bGrid[i+1][j])
                continue;
            if(!bGrid[i][j+1])
                continue;
            if(!bGrid[i+1][j+1])
                continue;

            ans++;
        }
    }

    cout << ans;
}