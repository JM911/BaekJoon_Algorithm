// 14500. 테트로미노
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
int paperNum[510][510];
bool isVisited[510][510];
int tmpSum;
int maxTet_1, maxTet_2;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void SearchMaxTet_1(int len, int prevX, int prevY)
{
    isVisited[prevX][prevY] = true;
    tmpSum += paperNum[prevX][prevY];
    
    if(len == 4)
    {
        maxTet_1 = max(maxTet_1, tmpSum);
        isVisited[prevX][prevY] = false;
        tmpSum -= paperNum[prevX][prevY];
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int x = prevX + dx[dir];
        int y = prevY + dy[dir];

        if(x<0 || y<0 || x>=N || y>=M)
            continue;
        
        if(isVisited[x][y] == true)
            continue;

        SearchMaxTet_1(len + 1, x, y);
    }

    isVisited[prevX][prevY] = false;
    tmpSum -= paperNum[prevX][prevY];
}

void SearchMaxTet_2(int curX, int curY)
{
    tmpSum += paperNum[curX][curY];
    
    int x, y;
    int count = 0;

    x = curX - 1;
    y = curY;
    if(x>=0)
    {
        count++;
        tmpSum += paperNum[x][y];
    }

    x = curX + 1;
    y = curY;
    if(x<N)
    {
        count++;
        tmpSum += paperNum[x][y];
    }

    x = curX;
    y = curY - 1;
    if(y>=0)
    {
        count++;
        tmpSum += paperNum[x][y];
    }

    x = curX;
    y = curY + 1;
    if(y<M)
    {
        count++;
        tmpSum += paperNum[x][y];
    }

    if(count == 4)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int noX = curX + dx[dir];
            int noY = curY + dy[dir];

            tmpSum -= paperNum[noX][noY];
            maxTet_2 = max(maxTet_2, tmpSum);
            tmpSum += paperNum[noX][noY];
        }
    }
    else if(count == 3)
    {
        maxTet_2 = max(maxTet_2, tmpSum);
    }

    
    tmpSum = 0;
}

int main()
{
    fastio;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> paperNum[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            SearchMaxTet_1(1, i, j);
            SearchMaxTet_2(i, j);
        }
    }

    cout << max(maxTet_1, maxTet_2);

    return 0;
}