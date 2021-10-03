// 1037. 약수
// S5

#include <iostream>
using namespace std;

void BSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int divNum[50] = { };

    for (int i = 0; i < n; i++)
    {
        cin >> divNum[i];
    }

    BSort(divNum, n);

    int minIndex = 0;

    cout << divNum[0] * divNum[n - 1];

    return 0;
}