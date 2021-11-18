// 2447. 별 찍기 - 10
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char stars[2188][2188];

void InputSpace(int startX, int startY, int N)
{
    if(N==1)
    {
        stars[startX][startY] = ' ';
        return;
    }

    int third = N / 3;

    InputSpace(startX, startY, third);
    InputSpace(startX, startY + third, third);
    InputSpace(startX, startY + third * 2, third);
    InputSpace(startX + third, startY, third);
    InputSpace(startX + third, startY + third, third);
    InputSpace(startX + third, startY + third * 2, third);
    InputSpace(startX + third * 2, startY, third);
    InputSpace(startX + third * 2, startY + third, third);
    InputSpace(startX + third * 2, startY + third * 2, third);
}

void InputStars(int startX, int startY, int N)
{
    if(N==1)
    {
        stars[startX][startY] = '*';
        return;
    }

    int third = N / 3;

    InputStars(startX, startY, third);
    InputStars(startX, startY + third, third);
    InputStars(startX, startY + third * 2, third);
    InputStars(startX + third, startY, third);
    InputSpace(startX + third, startY + third, third);
    InputStars(startX + third, startY + third * 2, third);
    InputStars(startX + third * 2, startY, third);
    InputStars(startX + third * 2, startY + third, third);
    InputStars(startX + third * 2, startY + third * 2, third);
}

int main()
{
    fastio;
    int N;
    cin >> N;

    InputStars(0, 0, N);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << stars[i][j];
        }
        cout << '\n';
    }

    return 0;
}
