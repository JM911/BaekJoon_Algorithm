// 1913. 달팽이
// S5

#include <iostream>
using namespace std;

enum DIRECTION
{
    DR_DOWN = 0,
    DR_RIGHT,
    DR_UP,
    DR_LEFT,
};

int dir = 0;

void MoveIndex(int* x, int* y)
{
    switch (dir)
    {
    case DR_DOWN:
        (*y)++;
        break;
    case DR_RIGHT:
        (*x)++;
        break;
    case DR_UP:
        (*y)--;
        break;
    case DR_LEFT:
        (*x)--;
        break;
    }
}

void UndoIndex(int* x, int* y)
{
    switch (dir)
    {
    case DR_DOWN:
        (*y)--;
        break;
    case DR_RIGHT:
        (*x)--;
        break;
    case DR_UP:
        (*y)++;
        break;
    case DR_LEFT:
        (*x)++;
        break;
    }
}

int main()
{
    int** arr;
    int N;
    cin >> N;
    N++;

    int search;
    cin >> search;

    arr = new int*[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[j][i] = 0;
        }
    }

    int xIndex = 0;
    int yIndex = 0;
    int num = (N - 1) * (N - 1);

    while (num > 0)
    {
        if (yIndex >= 0)
        {
            if (arr[yIndex][xIndex] == 0 && yIndex < N - 1 && xIndex < N - 1)
            {
                arr[yIndex][xIndex] = num;

                MoveIndex(&xIndex, &yIndex);

                num--;
            }
            else
            {
                UndoIndex(&xIndex, &yIndex);
                dir++;
                dir %= 4;
                MoveIndex(&xIndex, &yIndex);
            }
        }
        else
        {
            UndoIndex(&xIndex, &yIndex);
            dir++;
            dir %= 4;
            MoveIndex(&xIndex, &yIndex);
        }
    }

    int searchXIndex=0;
    int searchYIndex=0;

    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-1; j++)
        {
            cout << arr[i][j] << ' ';
            if (arr[i][j] == search)
            {
                searchXIndex = j+1;
                searchYIndex = i+1;
            }
        }
        cout << endl;
    }

    cout << searchYIndex << ' ' << searchXIndex;

    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}