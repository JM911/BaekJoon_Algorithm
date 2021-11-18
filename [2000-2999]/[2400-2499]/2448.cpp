// 2448. 별 찍기 - 11
// G4

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char stars[3073][6200];

void InputSpace(int startX, int startY, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            stars[startX + i][startY + j] = ' ';
        }
    }
}

void InputStars(int startX, int startY, int N)
{
    if(N==3)
    {
        stars[startX][startY] = ' ';
        stars[startX][startY+1] = ' ';
        stars[startX][startY+2] = '*';
        stars[startX][startY+3] = ' ';
        stars[startX][startY+4] = ' ';

        stars[startX+1][startY] = ' ';
        stars[startX+1][startY+1] = '*';
        stars[startX+1][startY+2] = ' ';
        stars[startX+1][startY+3] = '*';
        stars[startX+1][startY+4] = ' ';

        stars[startX+2][startY] = '*';
        stars[startX+2][startY+1] = '*';
        stars[startX+2][startY+2] = '*';
        stars[startX+2][startY+3] = '*';
        stars[startX+2][startY+4] = '*';

        return;
    }

    int half = N / 2;

    //InputSpace(startX, startY, half);
    InputStars(startX, startY + half, half);
    //InputSpace(startX, startY + half * 3 - 1, half);

    InputStars(startX + half, startY, half);
    // for (int i = 0; i < half; i++)
    // {
    //     stars[startX + half + i][startY + N - 1] = ' ';
    // }
    InputStars(startX + half, startY + N, half);
}

int main()
{
    fastio;
    int N;
    cin >> N;

    fill(&stars[0][0], &stars[3072][6200], ' ');
    InputStars(0, 0, N);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2 + 1; j++)
        {
            cout << stars[i][j];
        }
        cout << '\n';
    }

    return 0;
}
