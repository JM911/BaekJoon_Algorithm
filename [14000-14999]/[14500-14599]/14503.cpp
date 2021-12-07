// 14503. 로봇 청소기
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M, robX, robY, robDir;
int room[60][60];
int ans;

bool CheckCleaned()
{
    switch(robDir)
    {
    case 0:
        if(robX-1 >= 0 && room[robX-1][robY] == 0)
            return true;
        break;
    case 1:
        if(robY+1 < M && room[robX][robY+1] == 0)
            return true;
        break;
    case 2:
        if(robX+1 < N && room[robX+1][robY] == 0)
            return true;
        break;
    case 3:
        if(robY-1 >= 0 && room[robX][robY-1] == 0)
            return true;
        break;
    }

    return false;
}

void Cleaning()
{
    ans++;
    room[robX][robY] = 2;
}

void RotateLeft()
{
    robDir = (robDir + 3) % 4;
}

void GoToward()
{
    switch(robDir)
    {
    case 0:
        robX--;
        break;
    case 1:
        robY++;
        break;
    case 2:
        robX++;
        break;
    case 3:
        robY--;
        break;
    }
}

bool GoBackward()
{
    switch(robDir)
    {
    case 0:
        if(++robX < N && room[robX][robY] != 1)
            return true;
        break;
    case 1:
        if(--robY >= 0 && room[robX][robY] != 1)
            return true;
        break;
    case 2:
        if(--robX >= 0 && room[robX][robY] != 1)
            return true;
        break;
    case 3:
        if(++robY < M && room[robX][robY] != 1)
            return true;
        break;
    }

    return false;
}

int main()
{
    fastio;
    cin >> N >> M;
    cin >> robX >> robY >> robDir;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }

    while(true)
    {
        // 청소
        if(room[robX][robY] == 0)
            Cleaning();

        // 방향전환 후 체크 X4 
        bool isUncleaned = false;
        for (int i = 0; i < 4; i++)
        {
            RotateLeft();
            if(isUncleaned = CheckCleaned())
                break;
        }

        // 중간에 발견하면 움직이고 처음으로
        if(isUncleaned)
        {
            GoToward();
            continue;
        }

        // 4방향 모두 못가면 뒤로가고, 뒤로도 못가면 정지
        if(!GoBackward())
            break;
    }

    cout << ans;

    return 0;
}