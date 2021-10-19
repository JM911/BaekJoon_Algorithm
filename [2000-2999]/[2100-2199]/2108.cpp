// 2108. 통계학
// S4

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int frequency[8001];
int temp[8001];

void Merge(int* arr, int start, int mid, int end)
{
    int* sort_arr = new int[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            sort_arr[k++] = arr[i++];
        }
        else
        {
            sort_arr[k++] = arr[j++];
        }
    }

    if (i > mid)
    {
        while (j <= end)
        {
            sort_arr[k++] = arr[j++];
        }
    }

    else
    {
        while (i <= mid)
        {
            sort_arr[k++] = arr[i++];
        }
    }

    for (int t = start; t <= end; t++)
    {
        arr[t] = sort_arr[t - start];
    }

    delete[] sort_arr;
}

void Merge_Sort(int* arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        Merge_Sort(arr, start, mid);
        Merge_Sort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

int main()
{
    int N;
    cin >> N;
    int* arr = new int[N];
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        frequency[arr[i] + 4000]++;
        sum += arr[i];
    }
    
    float favg = static_cast<float>(sum) / N;
    if (favg < 0)
        favg -= 0.5f;
    else
        favg += 0.5f;
    int avg = static_cast<int>(favg); // 산술평균

    Merge_Sort(arr, 0, N - 1);

    int mid = arr[N / 2]; // 중앙값
    int range = arr[N - 1] - arr[0];  // 범위
    
    int maxIdx = 0;

    for (int i = 0; i < 8001; i++)
    {
        if (frequency[maxIdx] <= frequency[i])
            maxIdx = i;
    }

    int j = 0;
    for (int i = 0; i < 8001; i++)
    {
        if (frequency[maxIdx] == frequency[i])
            temp[j++] = i;
    }

    int maxFreq; // 최빈값
    if (j >= 2)
    {
        maxFreq = temp[1] - 4000;
    }

    else
    {
        maxFreq = temp[0] - 4000;
    }

    cout << avg << '\n';
    cout << mid << '\n';
    cout << maxFreq << '\n';
    cout << range << '\n';

    delete[] arr;

    return 0;
}
