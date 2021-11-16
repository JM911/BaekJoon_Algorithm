// 1780. 종이의 개수
// S2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int paper[2188][2188];
int numOfPaper[3];

int isSame(int x, int y, int len)
{
    if(len == 1)
    {
        numOfPaper[paper[x][y] + 1]++;
        return paper[x][y];
    }

    int a = len / 3;

    int leftTop     = isSame(x, y, a);
    int midTop      = isSame(x + a, y, a);
    int rightTop    = isSame(x + a * 2, y, a);

    int leftMid     = isSame(x, y + a, a);
    int midMid      = isSame(x + a, y + a, a);
    int rightMid    = isSame(x + a * 2, y + a, a);

    int leftBot     = isSame(x, y + a * 2, a);
    int midBot      = isSame(x + a, y + a * 2, a);
    int rightBot    = isSame(x + a * 2, y + a * 2, a);

    if(leftTop == midTop && leftTop == rightTop &&
        leftTop == leftMid && leftTop == midMid && leftTop == rightMid &&
        leftTop == leftBot && leftTop == midBot && leftTop == rightBot)
    {
        numOfPaper[leftTop + 1] -= 8;
        return leftTop;
    }

    return 2;
}

int main()
{
    fastio;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    isSame(0, 0, N);

    cout << numOfPaper[0] << '\n';
    cout << numOfPaper[1] << '\n';
    cout << numOfPaper[2] << '\n';
}
