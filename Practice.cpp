#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int bwData[65][65];

int whatColor(int startX, int startY, int len)  // 0: 흰색 통일, 1: 검은색 통일, 2: 통일 안됨
{
    if(len == 1)
        return bwData[startX][startY];

    int half = len / 2;

    int leftTop = whatColor(startX, startY, half);
    int rightTop = whatColor(startX, startY + half, half);
    int leftBot = whatColor(startX + half, startY, half);
    int rightBot = whatColor(startX + half, startY + half, half);

    if(leftTop == rightTop && leftTop == leftBot && leftTop == rightBot)
        return leftTop;
    else
        return 2;
}

void printQT(int startX, int startY, int len)
{
    int temp = whatColor(startX, startY, len);
    if(temp != 2)
    {
        cout << temp;
        return;
    }

    cout << '(';

    int half = len / 2;

    int leftTop = whatColor(startX, startY, half);
    int rightTop = whatColor(startX, startY + half, half);
    int leftBot = whatColor(startX + half, startY, half);
    int rightBot = whatColor(startX + half, startY + half, half);

    if(leftTop != 2)
        cout << leftTop;
    else
        printQT(startX, startY, half);
    
    if(rightTop != 2)
        cout << rightTop;
    else
        printQT(startX, startY + half, half);
    
    if(leftBot != 2)
        cout << leftBot;
    else
        printQT(startX + half, startY, half);
    
    if(rightBot != 2)
        cout << rightBot;
    else
        printQT(startX + half, startY + half, half);

    cout << ')';
}

int main()
{
    fastio;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string tempStr;
        cin >> tempStr;

        for (int j = 0; j < N; j++)
        {
            bwData[i][j] = tempStr[j] - '0';
        }
    }

    // if(N==1)
    // {
    //     cout << bwData[0][0];
    //     return 0;
    // }

    printQT(0, 0, N);
}
