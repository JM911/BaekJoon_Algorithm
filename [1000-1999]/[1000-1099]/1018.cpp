// 1018. 체스판 다시 칠하기
// S5

#include <iostream>
using namespace std;

int ChangeColor(char pan[9][9])
{
    int count1 = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 1)
            {
                if (pan[i][j] == 'W')
                {
                    pan[i][j] = 'B';
                    count1++;
                }
            }
            else
            {
                if (pan[i][j] == 'B')
                {
                    pan[i][j] = 'W';
                    count1++;
                }
            }
        }
    }

    if (count1 < 64 - count1)
        return count1;
    else
        return 64 - count1;
}

int main()
{
    char Chess[51][51] = { };
    int N, M;
    char PickPan[9][9] = { };

    cin >> N >> M;
    
    for (int i = 0; i <N ; i++)
    {
        cin >> Chess[i];
    }

    int minChange=64;

    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
        {
            for (int i2 = 0; i2 < 8; i2++)
            {
                for (int j2 = 0; j2 < 8; j2++)
                {
                    PickPan[i2][j2] = Chess[i + i2][j + j2];
                }
            }

            int temp = ChangeColor(PickPan);

            if (minChange > temp)
            {
                minChange = temp;
            }
        }
    }

    cout << minChange;

    return 0;
}