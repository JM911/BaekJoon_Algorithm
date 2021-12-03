// 14891. 톱니바퀴
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool gear[6][10];
bool willBeRotate[6];
bool isSameA, isSameB, isSameC;

void ClockwiseRotate(int idx)
{
    bool tmp = gear[idx][7];

    for (int i = 6; i >= 0; i--)
    {
        gear[idx][i + 1] = gear[idx][i];
    }

    gear[idx][0] = tmp;
}

void CounterwiseRotate(int idx)
{
    bool tmp = gear[idx][0];

    for (int i = 0; i < 7; i++)
    {
        gear[idx][i] = gear[idx][i + 1];
    }

    gear[idx][7] = tmp;
}

void RotateDir(int idx, int rotDir)
{
    if(rotDir == 1)
        ClockwiseRotate(idx);
    else
        CounterwiseRotate(idx);
}

void RotateAll(int firstRotIdx, int rotDir)
{
    switch(firstRotIdx)
    {
    case 1:
        RotateDir(1, rotDir);
        if(!isSameA)
            RotateDir(2, -rotDir);
        if(!isSameA && !isSameB)
            RotateDir(3, rotDir);
        if(!isSameA && !isSameB && !isSameC)
            RotateDir(4, -rotDir);
        break;

    case 2:
        RotateDir(2, rotDir);
        if(!isSameA)
            RotateDir(1, -rotDir);
        if(!isSameB)
            RotateDir(3, -rotDir);
        if(!isSameB && !isSameC)
            RotateDir(4, rotDir);
        break;

    case 3:
        RotateDir(3, rotDir);
        if(!isSameB)
            RotateDir(2, -rotDir);
        if(!isSameC)
            RotateDir(4, -rotDir);
        if(!isSameB && !isSameA)
            RotateDir(1, rotDir);
        break;

    case 4:
        RotateDir(4, rotDir);
        if(!isSameC)
            RotateDir(3, -rotDir);
        if(!isSameC && !isSameB)
            RotateDir(2, rotDir);
        if(!isSameC && !isSameB && !isSameA)
            RotateDir(1, -rotDir);
        break;
    }
}

int main()
{
    fastio;

    for (int i = 1; i <= 4; i++)
    {
        string tmpStr;
        cin >> tmpStr;

        for (int j = 0; j < 8; j++)
        {
            gear[i][j] = tmpStr[j] - '0';
        }
    }

    int K;
    cin >> K;

    while(K--)
    {
        isSameA = (gear[1][2] == gear[2][6]);
        isSameB = (gear[2][2] == gear[3][6]);
        isSameC = (gear[3][2] == gear[4][6]);

        int rotIdx, rotDir;
        cin >> rotIdx >> rotDir;

        RotateAll(rotIdx, rotDir);
    }

    int ans = gear[1][0] + gear[2][0] * 2 + gear[3][0] * 4 + gear[4][0] * 8;
    cout << ans;

    return 0;
}