// 1855. 암호
// B1

#include <iostream>
#include <cstring>
using namespace std;

void Decoding(char enc[], char dec[], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < row; j++)
            {
                dec[i * row + j] = enc[i * row + j];
            }
        }

        else
        {
            for (int j = 0; j < row; j++)
            {
                dec[i * row + j] = enc[(i + 1) * row - j - 1];
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            enc[col * i + j] = dec[j * row + i];
        }
    }
}

int main()
{
    int row, col;
    cin >> row;

    char encode[201];
    char decode[201] = { };

    cin >> encode;

    int len = strlen(encode);
    col = len / row;

    Decoding(encode, decode, row, col);

    cout << encode;

    return 0;
}