// 1475. 방 번호
// S5

#include <iostream>
#include <cstring>
using namespace std;

int Max(int arr[], int len)
{
    int max = 0;

    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

int main()
{
    char num[8];
    cin >> num;

    int len = strlen(num);

    int arr[10] = { };

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (num[i] == '0' + j)
                arr[j]++;
        }
    }

    arr[6] += arr[9];
    arr[6] = (arr[6] + 1) / 2;
    arr[9] = 0;

    cout << Max(arr, 9);

    return 0;
}