// 10989. 수 정렬하기 3
// S5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int arr[10001] = { };
    int temp;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        arr[temp] += 1;
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
