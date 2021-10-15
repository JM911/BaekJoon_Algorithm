// 10816. 숫자 카드2
// S4

#include <iostream>
using namespace std;

void merge(int* data, int start, int mid, int end)
{
    int* newData = new int[end - start + 1];

    int c1 = 0;
    int c2 = 0;

    while (start + c1 <= mid && mid + 1 + c2 <= end)
    {
        if (data[start + c1] > data[mid + 1 + c2])
        {
            newData[c1 + c2] = data[mid + 1 + c2];
            c2++;
        }

        else
        {
            newData[c1 + c2] = data[start + c1];
            c1++;
        }
    }

    if (start + c1 > mid)
    {
        while (mid + 1 + c2 <= end)
        {
            newData[c1 + c2] = data[mid + 1 + c2];
            c2++;
        }
    }

    else
    {
        while (start + c1 <= mid)
        {
            newData[c1 + c2] = data[start + c1];
            c1++;
        }
    }

    for (int i = start; i <= end; i++)
    {
        data[i] = newData[i - start];
    }
}

void merge_sort(int* data, int start, int end)
{
    if (start < end)
    {
        int mid = (end + start) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}

int BSearch(int* arr, int target, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] < target)
        return BSearch(arr, target, mid + 1, end);

    else
        return BSearch(arr, target, start, mid - 1);
}

int LowerBound(int* arr, int target, int start, int end)
{
    if (arr[end] != target)
        return end + 1;

    if (start >= end)
        return end;

    int mid = (start + end) / 2;

    if (arr[mid] < target)
        return LowerBound(arr, target, mid + 1, end);
    else
        return LowerBound(arr, target, start, mid-1);
}

int UpperBound(int* arr, int target, int start, int end)
{
    if (arr[start] != target)
        return start - 1;

    if (start >= end)
        return start;

    int mid = (start + end) / 2;

    if (arr[mid] > target)
        return UpperBound(arr, target, start, mid - 1);
    else
        return UpperBound(arr, target, mid+1, end);
}

int main()
{
    int N;
    cin >> N;
    int* card = new int[N];

    for (int i = 0; i < N; i++)
        cin >> card[i];

    merge_sort(card, 0, N - 1);

    int M;
    cin >> M;
    int* target = new int[M];

    for (int i = 0; i < M; i++)
        cin >> target[i];

    for (int i = 0; i < M; i++)
    {
        int idx = BSearch(card, target[i], 0, N - 1);

        if (idx == -1)
        {
            target[i] = 0;
            continue;
        }

        else
        {
            int max = UpperBound(card, target[i], idx, N - 1);
            int min = LowerBound(card, target[i], 0, idx);

            target[i] = max - min + 1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        cout << target[i] << ' ';
    }

    return 0;
}