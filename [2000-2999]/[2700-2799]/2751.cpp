// 2751. 수 정렬하기 2
// S5

#include <iostream>
using namespace std;

void MergeSort(int arr[], int len)
{
    if (len == 1)
    {
        return;
    }
    int len1 = len / 2;
    int len2 = len - len1;

    int* copy1 = new int[len1];
    int* copy2 = new int[len2];

    for (int i = 0; i < len1; i++)
    {
        copy1[i] = arr[i];
        copy2[i] = arr[len1 + i];
    }
    copy2[len2 - 1] = arr[len - 1];

    MergeSort(copy1, len1);
    MergeSort(copy2, len2);

    int count1 = 0;
    int count2 = 0;

    while (count1 < len1 || count2 < len2)
    {
        if (count1 == len1)
        {
            arr[count1 + count2] = copy2[count2];
            count2++;
        }

        else if (count2 == len2)
        {
            arr[count1 + count2] = copy1[count1];
            count1++;
        }

        else if (copy1[count1] < copy2[count2])
        {
            arr[count1 + count2] = copy1[count1];
            count1++;
        }
        else
        {
            arr[count1 + count2] = copy2[count2];
            count2++;
        }
    }

    delete[] copy1;
    delete[] copy2;
}

int main()
{
    int N;
    cin >> N;
    int* arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    if (N == 1)
    {
        cout << arr[0];
        delete[] arr;
        return 0;
    }

    else
    {
        MergeSort(arr, N);

        for (int i = 0; i < N; i++)
            cout << arr[i] << '\n';

        delete[] arr;
    }
    
    return 0;
}