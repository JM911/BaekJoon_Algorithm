// 15683. 감시
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
int office[10][10];
int isMonitered[10][10];
int ans = INT_MAX;

void GetCamRegion_1(int x, int y, int dir)
{
    switch(dir)
    {
    case 0:
        while(--x>=0 && office[x][y] != 6)
            isMonitered[x][y]++;
        break;
    case 1:
        while(--y>=0 && office[x][y] != 6)
            isMonitered[x][y]++;
        break;
    case 2:
        while(++x<N && office[x][y] != 6)
            isMonitered[x][y]++;
        break;
    case 3:
        while(++y<M && office[x][y] != 6)
            isMonitered[x][y]++;
        break;
    }
}

void ReleaseCamRegion_1(int x, int y, int dir)
{
    switch(dir)
    {
    case 0:
        while(--x>=0 && office[x][y] != 6)
            isMonitered[x][y]--;
        break;
    case 1:
        while(--y>=0 && office[x][y] != 6)
            isMonitered[x][y]--;
        break;
    case 2:
        while(++x<N && office[x][y] != 6)
            isMonitered[x][y]--;
        break;
    case 3:
        while(++y<M && office[x][y] != 6)
            isMonitered[x][y]--;
        break;
    }
}


void CheckOffice(int curX, int curY)
{
    if(curX == N)
    {
        int blindSpot = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(isMonitered[i][j] == 0)
                    blindSpot++;
            }
        }

        ans = min(ans, blindSpot);

        return;
    }
    
    if(curY == M)
    {
        CheckOffice(curX + 1, 0);
        return;
    }

    int camNum = office[curX][curY];
    int x, y;

    switch(camNum)
    {
    case 1:
        GetCamRegion_1(curX, curY, 0);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 0);

        GetCamRegion_1(curX, curY, 1);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 1);
        
        GetCamRegion_1(curX, curY, 2);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 2);
        
        GetCamRegion_1(curX, curY, 3);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 3);

        break;

    case 2:
        GetCamRegion_1(curX, curY, 0);
        GetCamRegion_1(curX, curY, 2);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 0);
        ReleaseCamRegion_1(curX, curY, 2);


        GetCamRegion_1(curX, curY, 1);
        GetCamRegion_1(curX, curY, 3);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 1);
        ReleaseCamRegion_1(curX, curY, 3);

        break;

    case 3:
        GetCamRegion_1(curX, curY, 0);
        GetCamRegion_1(curX, curY, 1);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 0);
        ReleaseCamRegion_1(curX, curY, 1);

        GetCamRegion_1(curX, curY, 1);
        GetCamRegion_1(curX, curY, 2);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 1);
        ReleaseCamRegion_1(curX, curY, 2);
        
        GetCamRegion_1(curX, curY, 2);
        GetCamRegion_1(curX, curY, 3);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 2);
        ReleaseCamRegion_1(curX, curY, 3);
        
        GetCamRegion_1(curX, curY, 3);
        GetCamRegion_1(curX, curY, 0);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 3);
        ReleaseCamRegion_1(curX, curY, 0);

        break;

    case 4:
        GetCamRegion_1(curX, curY, 0);
        GetCamRegion_1(curX, curY, 1);
        GetCamRegion_1(curX, curY, 2);
        GetCamRegion_1(curX, curY, 3);

        ReleaseCamRegion_1(curX, curY, 0);
        CheckOffice(curX, curY + 1);
        GetCamRegion_1(curX, curY, 0);

        ReleaseCamRegion_1(curX, curY, 1);
        CheckOffice(curX, curY + 1);
        GetCamRegion_1(curX, curY, 1);

        ReleaseCamRegion_1(curX, curY, 2);
        CheckOffice(curX, curY + 1);
        GetCamRegion_1(curX, curY, 2);

        ReleaseCamRegion_1(curX, curY, 3);
        CheckOffice(curX, curY + 1);

        ReleaseCamRegion_1(curX, curY, 0);
        ReleaseCamRegion_1(curX, curY, 1);
        ReleaseCamRegion_1(curX, curY, 2);

        break;

    case 5:
        GetCamRegion_1(curX, curY, 0);
        GetCamRegion_1(curX, curY, 1);
        GetCamRegion_1(curX, curY, 2);
        GetCamRegion_1(curX, curY, 3);
        CheckOffice(curX, curY + 1);
        ReleaseCamRegion_1(curX, curY, 0);
        ReleaseCamRegion_1(curX, curY, 1);
        ReleaseCamRegion_1(curX, curY, 2);
        ReleaseCamRegion_1(curX, curY, 3);

        break;

    default:
        CheckOffice(curX, curY + 1);
        break;
    }
}

int main()
{
    fastio;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> office[i][j];

            if(office[i][j] != 0)
                isMonitered[i][j]++;
        }
    }

    CheckOffice(0, 0);

    cout << ans;
}