// 2798. 블랙잭
// B2

#include <iostream>
using namespace std;

int main()
{
    int N, target;
    cin >> N >> target;
    int* arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int max = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (i != j && j != k && k != i)
                {
                    int temp = arr[i] + arr[j] + arr[k];
                    if (temp <= target && target - max > target - temp)
                        max = temp;
                }
            }
        }
    }

    cout << max;

    return 0;
}