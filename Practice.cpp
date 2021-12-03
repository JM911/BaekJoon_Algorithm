#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M, x, y, K;
int topNum, bottomNum, leftNum, rightNum, frontNum, backNum;
int mapNum[30][30];

void CheckBottom()
{
    if(mapNum[x][y] == 0)
        mapNum[x][y] = bottomNum;

    else
    {
        bottomNum = mapNum[x][y];
        mapNum[x][y] = 0;
    }
}

void RollEast()
{
    int tmp = bottomNum;
    bottomNum = rightNum;
    rightNum = topNum;
    topNum = leftNum;
    leftNum = tmp;

    y++;
}

void RollWest()
{
    int tmp = bottomNum;
    bottomNum = leftNum;
    leftNum = topNum;
    topNum = rightNum;
    rightNum = tmp;

    y--;
}

void RollNorth()
{
    int tmp = bottomNum;
    bottomNum = backNum;
    backNum = topNum;
    topNum = frontNum;
    frontNum = tmp;

    x--;
}

void RollSouth()
{
    int tmp = bottomNum;
    bottomNum = frontNum;
    frontNum = topNum;
    topNum = backNum;
    backNum = tmp;

    x++;
}

int main()
{
    //fastio;
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mapNum[i][j];
        }
    }

    while(K--)
    {
        int dir;
        cin >> dir;

        bool rolling = true;

        switch(dir)
        {
        case 1:
            if(y==M-1)
                rolling = false;
            else
                RollEast();
            break;

        case 2:
            if(y==0)
                rolling = false;
            else
                RollWest();
            break;

        case 3:
            if(x==0)
                rolling = false;
            else
                RollNorth();
            break;

        case 4:
            if(x==N-1)
                rolling = false;
            else
                RollSouth();
            break;
        }

        if(rolling)
        {
            CheckBottom();
            cout << topNum << '\n';
        }
    }

        return 0;
}